#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define SHIFT_ARR 3
void FillDpInLoop(int32_t seq_length, int32_t*** dp, const int64_t kKRing,
                  std::vector<int32_t> arr) {
  for (int32_t i = seq_length - SHIFT_ARR; i >= 0; --i) {
    for (int32_t j = i + 2; j < seq_length; ++j) {
      *dp[i][j] =
          ((*dp[i + 1][j] + *dp[i][j - 1] - *dp[i + 1][j - 1] + kKRing) %
           kKRing);
      if (arr[i] != arr[j]) {
        *dp[i][j] %= kKRing;
        continue;
      }
      *dp[i][j] += ((*dp[i + 1][j - 1] + 1) % kKRing);
      *dp[i][j] %= kKRing;
    }
  }
}
int main() {
  const int64_t kKRing = 1e9;
  int32_t seq_length;
  std::cin >> seq_length;
  std::vector<int32_t> arr(seq_length);
  for (int32_t i = 0; i < seq_length; ++i) {
    std::cin >> arr[i];
  }
  int32_t** dp = new int32_t*[seq_length];
  for (int32_t i = 0; i < seq_length; ++i) {
    dp[i] = new int32_t[seq_length];
    dp[i][i] = 1;
  }
  for (int32_t i = 1; i < seq_length; ++i) {
    dp[i - 1][i] = 2;
    if (arr[i - 1] != arr[i]) {
      continue;
    }
    ++dp[i - 1][i];
  }
  FillDpInLoop(seq_length, &dp, kKRing, arr);
  std::cout << (dp[0][seq_length - 1]);
  return 0;
}