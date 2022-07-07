#include <iostream>
#include <vector>
#define BYTE_MAX 255
#define BITS 8
inline int GetSectionByte(uint64_t num, const int kShift) {
  return num >> (BITS * kShift) & BYTE_MAX;
}

void CountSort(std::vector<uint64_t>& array, int size, const int kShift) {
  std::vector<size_t> count;
  std::vector<uint64_t> ans;
  int i;
  for (i = 0; i < size; ++i) {
    ans.push_back(0);
  }
  for (i = 0; i < BYTE_MAX + 1; ++i) {
    count.push_back(0);
  }
  for (i = 0; i < size; ++i) {
    count[GetSectionByte(array[i], kShift)]++;
  }
  for (i = 1; i < BYTE_MAX + 1; ++i) {
    count[i] += count[i - 1];
  }
  for (i = size - 1; i >= 0; --i) {
    ans[--count[GetSectionByte(array[i], kShift)]] = array[i];
  }
  for (i = 0; i < size; ++i) {
    array[i] = ans[i];
  }
}

int main() {
  int arr_sz;
  scanf("%d", &arr_sz);
  std::vector<uint64_t> array;
  uint64_t val;
  for (int i = 0; i < arr_sz; ++i) {
    scanf("%lu", &val);
    array.push_back(val);
  }
  for (size_t byte = 0; byte < sizeof(uint64_t); ++byte) {
    CountSort(array, arr_sz, byte);
  }
  for (int i = 0; i < arr_sz; ++i) {
    printf("%lu\n", array[i]);
  }
  array.clear();
  return 0;
}