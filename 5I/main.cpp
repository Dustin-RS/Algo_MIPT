#include <inttypes.h>

#include <iostream>
#include <vector>
void ReversePrint(uint32_t** dp, std::vector<uint32_t> weight, size_t i,
                  size_t k) {
  if (dp[i][k] == 0) {
    return;
  }
  if (dp[i - 1][k] == dp[i][k]) {
    ReversePrint(dp, weight, i - 1, k);
  } else {
    ReversePrint(dp, weight, i - 1, k - weight[i - 1]);
    std::cout << i << std::endl;
  }
}
void FillDpInLoop(size_t n, size_t m, std::vector<uint32_t> weight,
                  uint32_t*** dp, std::vector<uint32_t> cost) {
  for (size_t i = 1; i < n + 1; ++i) {
    for (size_t k = 1; k < m + 1; ++k) {
      if (k >= weight[i - 1]) {
        dp[i][k] = std::max((dp[i - 1][k - weight[i - 1]] + cost[i - 1]),
                            dp[i - 1][k]);
      } else {
        dp[i][k] = dp[i - 1][k];
      }
    }
  }
}
int main() {
  size_t n;
  size_t m;
  std::cin >> n >> m;
  std::vector<uint32_t> weight(n);
  std::vector<uint32_t> cost(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> weight[i];
  }
  for (size_t i = 0; i < n; ++i) {
    std::cin >> cost[i];
  }
  uint32_t** dp = new uint32_t*[n + 1];
  for (size_t i = 0; i < n + 1; ++i) {
    dp[i] = new uint32_t[m + 1];
  }
  for (size_t i = 0; i < n + 1; ++i) {
    dp[i][0] = 0;
  }
  for (size_t i = 0; i < m + 1; ++i) {
    dp[0][i] = 0;
  }
  FillDpInLoop(n, m, weight, &dp, cost);
  ReversePrint(dp, weight, n, m);
  return 0;
}