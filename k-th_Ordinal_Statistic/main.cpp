#include <iostream>
int Partition(int* arr, int start, int end) {
  int pivot = arr[(start + end) / 2];
  int i = start;
  int j = end;
  while (i <= j) {
    while (arr[i] < pivot) {
      ++i;
    }
    while (pivot < arr[j]) {
      --j;
    }
    if (i >= j) {
      break;
    }
    std::swap(arr[i], arr[j]);
    ++i;
    --j;
  }
  return j;
}
int FindOrdinalStatistics(int* arr, int ord, int start, int end) {
  int j = Partition(arr, start, end);
  if (j == ord) {
    return arr[j];
  }
  if (j > ord) {
    return FindOrdinalStatistics(arr, ord, start, j);
  }
  return FindOrdinalStatistics(arr, ord, j + 1, end);
}
int main() {
  int arr_sz;
  int ordinal_statistics;
  const int kRING = 10000000 + 4321;
  const int kMULT1 = 123;
  const int kMULT2 = 45;
  std::cin >> arr_sz >> ordinal_statistics;
  int* arr = new int[arr_sz];
  std::cin >> arr[0] >> arr[1];
  for (int i = 2; i < arr_sz; ++i) {
    arr[i] = (arr[i - 1] * kMULT1 + arr[i - 2] * kMULT2) % (kRING);
  }
  std::cout << FindOrdinalStatistics(arr, ordinal_statistics - 1, 0, arr_sz - 1)
            << std::endl;
  delete[] arr;
  return 0;
}