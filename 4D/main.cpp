#include <iostream>
#include <vector>
class FenwikTree {
 private:
  std::vector<std::vector<int64_t>> arr_;
  std::vector<std::vector<int64_t>> tree_;

 public:
  FenwikTree(size_t n, size_t m) {
    arr_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      arr_[i].assign(m, 0);
    }
    tree_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      tree_[i].assign(m, 0);
    }
  }
  int64_t Sum(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    return (GetSum(x2, y2) - GetSum(x1 - 1, y2) - GetSum(x2, y1 - 1) +
            GetSum(x1 - 1, y1 - 1));
  }
  int64_t GetSum(int32_t x, int32_t y) {
    int64_t ans = 0;
    for (int32_t i = x; i >= 0; i = (i & (i + 1)) - 1) {
      for (int32_t j = y; j >= 0; j = (j & (j + 1)) - 1) {
        ans += tree_[i][j];
      }
    }
    return ans;
  }
  void Update(int32_t x, int32_t y, int64_t new_val) {
    UpdateDelta(x, y, new_val);
  }
  void UpdateDelta(int32_t x, int32_t y, int64_t delta) {
    for (size_t i = x; i < tree_.size(); i |= (i + 1)) {
      for (size_t j = y; j < tree_[0].size(); j |= (j + 1)) {
        tree_[i][j] += delta;
      }
    }
  }
};
int main() {
  int16_t ans;
  size_t n_size;
  size_t m_size;
  size_t query_amount;
  int32_t x1;
  int32_t x2;
  int32_t y1;
  int32_t y2;
  int64_t new_val;
  std::cin >> n_size >> m_size;
  FenwikTree tree(n_size, m_size);
  std::cin >> query_amount;
  for (size_t i = 0; i < query_amount; ++i) {
    std::cin >> ans;
    switch (ans) {
      case 1: {
        std::cin >> x1 >> y1 >> new_val;
        tree.Update(x1 - 1, y1 - 1, new_val);
        break;
      }
      case 2: {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << tree.Sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << std::endl;
        break;
      }
    }
  }
  return 0;
}