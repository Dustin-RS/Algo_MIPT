#include <iostream>
void MergeArrays(const int* arr1, const int* arr2, int arr1_sz, int arr2_sz) {
  int i = 0;
  int j = 0;
  int ii = 0;
  int arr3_sz = arr1_sz + arr2_sz;
  int* arr3 = new int[arr3_sz];
  while (i < arr1_sz && j < arr2_sz) {
    if (arr1[i] > arr2[j]) {
      arr3[ii++] = arr2[j++];
    } else {
      arr3[ii++] = arr1[i++];
    }
  }
  while (i < arr1_sz) {
    arr3[ii++] = arr1[i++];
  }
  while (j < arr2_sz) {
    arr3[ii++] = arr2[j++];
  }
  for (i = 0; i < arr3_sz; ++i) {
    std::cout << arr3[i] << ' ';
  }
  std::cout << std::endl;
  delete[] arr3;
}
int main() {
  int arr1_sz;
  int arr2_sz;
  std::cin >> arr1_sz;
  int* arr1 = new int[arr1_sz];
  for (int i = 0; i < arr1_sz; ++i) {
    std::cin >> arr1[i];
  }
  std::cin >> arr2_sz;
  int* arr2 = new int[arr2_sz];
  for (int i = 0; i < arr2_sz; ++i) {
    std::cin >> arr2[i];
  }
  MergeArrays(arr1, arr2, arr1_sz, arr2_sz);
  delete[] arr1;
  delete[] arr2;
  return 0;
}