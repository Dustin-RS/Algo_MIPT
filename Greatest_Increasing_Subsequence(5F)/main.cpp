#include <inttypes.h>

#include <iostream>
#include <vector>
void DpFillInLoop(std::vector<int32_t> dp, std::vector<int32_t> prev_idx,
                  std::vector<int32_t> a, int32_t n) {
  for (int32_t i = 0; i < n; ++i) {
    dp[i] = 1;
    prev_idx[i] = -1;
    for (int32_t j = 0; j < i; ++j) {
      if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev_idx[i] = j;
      }
    }
  }
}
int main() {
  int32_t n;
  std::cin >> n;
  std::vector<int32_t> a(n);
  for (int32_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int32_t> dp(n);
  std::vector<int32_t> prev_idx(n);
  DpFillInLoop(dp, prev_idx, a, n);
  int32_t rev_idx = 0;
  int32_t dp_max_sz = dp[0];
  for (int32_t i = 0; i < n; ++i) {
    if (dp[i] > dp_max_sz) {
      rev_idx = i;
    }
    dp_max_sz = std::max(dp_max_sz, dp[i]);
  }
  dp.clear();
  dp.reserve(n);
  while (rev_idx != -1) {
    dp.push_back(a[rev_idx]);
    rev_idx = prev_idx[rev_idx];
  }
  for (int32_t i = dp.size() - 1; i > 0; --i) {
    std::cout << dp[i] << " ";
  }
  std::cout << dp[0] << std::endl;
}