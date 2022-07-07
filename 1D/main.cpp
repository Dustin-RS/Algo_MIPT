#include <iostream>
#define BEGINDEX_ENDINDEX_TARGET 3
bool BinarySearch(int* begin, int* end, int target);
bool BinarySearch(int* begin, int* end, int target) {
  if (end - begin == 1) {
    return *begin == target;
  }
  int* mid = begin + (end - begin) / 2;
  if (*mid > target) {
    return BinarySearch(begin, mid, target);
  }
  if (*mid < target) {
    return BinarySearch(mid, end, target);
  }
  return *mid == target;
}
int main() {
  int arr_sz;
  int inquiry;
  std::cin >> arr_sz;
  int* arr = new int[arr_sz];
  for (int i = 0; i < arr_sz; i++) {
    std::cin >> arr[i];
  }
  std::cin >> inquiry;
  int* query = new int[inquiry];
  for (int i = 0; i < inquiry; i++) {
    for (int j = 0; j < BEGINDEX_ENDINDEX_TARGET; j++) {
      std::cin >> query[j];
    }
    if (BinarySearch(arr + query[0], arr + query[1], query[2])) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  delete[] arr;
  delete[] query;
}