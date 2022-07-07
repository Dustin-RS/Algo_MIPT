#include <inttypes.h>
#include <iostream>
#include <vector>
void RecPrint(std::pair<int32_t, int32_t>** prev_idx, int32_t* arr1, int32_t i,
             int32_t j) {
  if (i == 0 || j == 0) {
    return;
  }
  if ( prev_idx[i][j] == std::pair<int32_t, int32_t>(i - 1, j - 1)) {
    RecPrint(prev_idx, arr1, i - 1, j - 1);
    std::cout << arr1[i-1] << " ";
  } else {
    if (prev_idx[i][j] == std::pair<int32_t, int32_t>(i - 1, j)) {
      RecPrint(prev_idx, arr1, i - 1, j);
    } else {
      RecPrint(prev_idx, arr1, i, j - 1);   
    }
  }
}
int main() {
  size_t N;
  std::cin >> N;
  int32_t* arr1 = new int32_t[N];
  for (size_t i = 0; i < N; ++i) {
    std::cin >> arr1[i];
  }
  size_t M;
  std::cin >> M;
  int32_t* arr2 = new int32_t[M];
  for (size_t i = 0; i < M; ++i) {
    std::cin >> arr2[i];
  }
  int32_t** dp = new int32_t*[N + 1];
  std::pair<int32_t, int32_t>** prev_idx =
      new std::pair<int32_t, int32_t>*[N + 1];
  for (size_t i = 0; i < N + 1; ++i) {
    dp[i] = new int32_t[M + 1];
    prev_idx[i] = new std::pair<int32_t, int32_t>[M + 1];
  }
  for (size_t i = 0; i < N + 1; ++i) {
    dp[i][0] = 0;
  }
  for (size_t i = 0; i < M + 1; ++i) {
    dp[0][i] = 0;
  }
  for (int32_t i = 1; i < N + 1; ++i) {
    for (int32_t j = 1; j < M + 1; ++j) {
      if (arr1[i-1] == arr2[j-1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        prev_idx[i][j] = {i - 1, j - 1};
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          prev_idx[i][j] = {i - 1, j};
        } else {
          dp[i][j] = dp[i][j - 1];
          prev_idx[i][j] = {i, j - 1};
        }
      }
    }
  }
  size_t ii = 0;
  RecPrint(prev_idx, arr1, N, M);
  std::cout << std::endl;
  return 0;
}
