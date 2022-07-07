#include <iostream>
#include <vector>
#define EXIT_CODE 3
#define X_INDEX 3
#define Y_INDEX 4
#define Z_INDEX 5
#define ELEMENTS_IN_DIMENSIAL 6
class FenwikTree {
 private:
  std::vector<std::vector<std::vector<int64_t>>> arr_;
  std::vector<std::vector<std::vector<int64_t>>> tree_;

 public:
  FenwikTree(size_t n) {
    arr_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      arr_[i].resize(n);
      for (size_t j = 0; j < n; ++j) {
        arr_[i][j].assign(n, 0);
      }
    }
    tree_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      tree_[i].resize(n);
      for (size_t j = 0; j < n; ++j) {
        tree_[i][j].assign(n, 0);
      }
    }
  }
  int64_t Sum(std::vector<int32_t> coordinates) {
    return (
        GetSum(coordinates[X_INDEX], coordinates[Y_INDEX],
               coordinates[Z_INDEX]) -
        GetSum(coordinates[0] - 1, coordinates[Y_INDEX], coordinates[Z_INDEX]) -
        GetSum(coordinates[X_INDEX], coordinates[1] - 1, coordinates[Z_INDEX]) +
        GetSum(coordinates[0] - 1, coordinates[1] - 1, coordinates[Z_INDEX]) -
        GetSum(coordinates[X_INDEX], coordinates[Y_INDEX], coordinates[2] - 1) +
        GetSum(coordinates[0] - 1, coordinates[Y_INDEX], coordinates[2] - 1) +
        GetSum(coordinates[X_INDEX], coordinates[1] - 1, coordinates[2] - 1) -
        GetSum(coordinates[0] - 1, coordinates[1] - 1, coordinates[2] - 1));
  }
  int64_t GetSum(int32_t x, int32_t y, int32_t z) {
    int64_t ans = 0;
    for (int32_t i = x; i >= 0; i = (i & (i + 1)) - 1) {
      for (int32_t j = y; j >= 0; j = (j & (j + 1)) - 1) {
        for (int32_t ii = z; ii >= 0; ii = (ii & (ii + 1)) - 1) {
          ans += tree_[i][j][ii];
        }
      }
    }
    return ans;
  }
  void Update(int32_t x, int32_t y, int32_t z, int64_t new_val) {
    UpdateDelta(x, y, z, new_val);
  }
  void UpdateDelta(int32_t x, int32_t y, int32_t z, int64_t delta) {
    for (size_t i = x; i < tree_.size(); i |= (i + 1)) {
      for (size_t j = y; j < tree_[0].size(); j |= (j + 1)) {
        for (size_t ii = z; ii < tree_[0][0].size(); ii |= (ii + 1)) {
          tree_[i][j][ii] += delta;
        }
      }
    }
  }
};
int main() {
  int16_t ans;
  size_t n_size;
  int32_t x1;
  int32_t x2;
  int32_t y1;
  int32_t y2;
  int32_t z1;
  int32_t z2;
  int64_t new_val;
  std::cin >> n_size;
  FenwikTree tree(n_size);
  std::vector<int32_t> coordinates(ELEMENTS_IN_DIMENSIAL);
  while (true) {
    std::cin >> ans;
    switch (ans) {
      case 1:
        std::cin >> x1 >> y1 >> z1 >> new_val;
        tree.Update(x1, y1, z1, new_val);
        break;
      case 2:
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        coordinates = {x1, y1, z1, x2, y2, z2};
        std::cout << tree.Sum(coordinates) << std::endl;
        break;
      case EXIT_CODE:
        return 0;
    }
  }
}