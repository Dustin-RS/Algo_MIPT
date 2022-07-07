#include <iostream>
void Swap(int* val1, int* val2) {
  int tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}
int Partician(int* arr, int start, int end) {
  int pivot = arr[start];
  int pointer1 = start + 1;
  int pointer2 = start + 1;

  for (; pointer2 <= end; ++pointer2) {
    if (arr[pointer2] < pivot) {
      if (pointer2 != pointer1) {
        Swap(&arr[pointer1], &arr[pointer2]);
      }
      pointer1++;
    }
  }
  arr[start] = arr[pointer1 - 1];
  arr[pointer1 - 1] = pivot;
  return pointer1 - 1;
}
void QuickSort(int* arr, int low, int high) {
  if (low < high) {
    int pivot_index = Partician(arr, low, high);

    QuickSort(arr, low, pivot_index - 1);
    QuickSort(arr, pivot_index + 1, high);
  }
}
int main() {
  size_t arr_sz;
  std::cin >> arr_sz;
  int* arr = new int[arr_sz];
  for (size_t i = 0; i < arr_sz; ++i) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, arr_sz - 1);
  for (size_t i = 0; i < arr_sz; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
  delete[] arr;
  return 0;
}