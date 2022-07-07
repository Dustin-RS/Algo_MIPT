#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
int main() {
  const int32_t kInfVal = 1e6;
  int32_t seq_length;
  std::cin >> seq_length;
  std::vector<int32_t> seq(seq_length);
  for (int32_t i = 0; i < seq_length; ++i) {
    std::cin >> seq[i];
  }
  int32_t* dp = new int32_t[seq_length];
  int32_t length = 0;
  dp[0] = -kInfVal;
  for (int32_t i = 1; i < seq_length; ++i) {
    dp[i] = kInfVal;
  }
  for (int32_t i = 0; i < seq_length; ++i) {
    int32_t j = std::lower_bound(dp, dp + seq_length, seq[i]) - dp;
    if (dp[j - 1] < seq[i] && seq[i] < dp[j]) {
      dp[j] = seq[i];
      length = std::max(length, j);
    }
  }
  std::cout << length << std::endl;
  return 0;
}