#include <iostream>
#include <vector>
std::vector<int> MergeArrays(std::vector<int> arr1, std::vector<int> arr2) {
  size_t i = 0;
  size_t j = 0;
  size_t arr1_sz = arr1.size();
  size_t arr2_sz = arr2.size();
  std::vector<int> arr3;
  while (i < arr1_sz && j < arr2_sz) {
    if (arr1[i] > arr2[j]) {
      arr3.push_back(arr2[j++]);
    } else {
      arr3.push_back(arr1[i++]);
    }
  }
  while (i < arr1_sz) {
    arr3.push_back(arr1[i++]);
  }
  while (j < arr2_sz) {
    arr3.push_back(arr2[j++]);
  }
  return arr3;
}
void FillArr(std::vector<std::vector<int>>& arrs, std::vector<int>& sizes,
             int union_amount) {
  std::vector<int> tmp_arr;
  for (int i = 0; i < union_amount; ++i) {
    int val;
    std::cin >> val;
    sizes.push_back(val);
    for (int j = 0; j < sizes[i]; ++j) {
      std::cin >> val;
      tmp_arr.push_back(val);
    }
    arrs.push_back(tmp_arr);
    tmp_arr.clear();
  }
}
void PrintArr(std::vector<std::vector<int>> arrs, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arrs[0][i] << ' ';
  }
  std::cout << std::endl;
}
int main() {
  int union_amount;
  std::cin >> union_amount;
  std::vector<std::vector<int>> arrs;
  std::vector<int> sizes;
  FillArr(arrs, sizes, union_amount);
  int cur_amount_arr = union_amount;
  int i = 0;
  while (cur_amount_arr != 1) {
    for (i = 0; i < cur_amount_arr / 2; ++i) {
      arrs[i] = MergeArrays(arrs[2 * i], arrs[2 * i + 1]);
      sizes[i] = sizes[2 * i] + sizes[2 * i + 1];
    }
    if (cur_amount_arr % 2 == 1) {
      sizes[i] = sizes[2 * i];
      arrs[i] = arrs[2 * i];
      cur_amount_arr /= 2;
      ++cur_amount_arr;
    } else {
      cur_amount_arr /= 2;
    }
  }
  PrintArr(arrs, sizes[0]);
  arrs.clear();
  sizes.clear();
  return 0;
}