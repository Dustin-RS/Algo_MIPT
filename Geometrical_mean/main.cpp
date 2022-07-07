#include <cmath>
#include <iostream>
int main() {
  int arr_sz;
  int query;
  std::cin >> arr_sz;
  double* arr = new double[arr_sz + 1];
  double s;
  arr[0] = 0;
  for (int i = 1; i < arr_sz + 1; ++i) {
    std::cin >> s;
    arr[i] = log(s) + arr[i - 1];
  }
  std::cin >> query;
  int* d_arr = new int[query];
  int* u_arr = new int[query];
  for (int i = 0; i < query; ++i) {
    std::cin >> d_arr[i] >> u_arr[i];
  }
  for (int i = 0; i < query; ++i) {
    printf("%.10f\n", exp((arr[u_arr[i] + 1] - arr[d_arr[i]]) /
                          (u_arr[i] - d_arr[i] + 1)));
  }
  delete[] d_arr;
  delete[] u_arr;
  delete[] arr;
  return 0;
}