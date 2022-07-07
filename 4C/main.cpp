#include <iostream>
#include <vector>
class FenwikTree {
 private:
  std::vector<int64_t> arr_;
  std::vector<int64_t> tree_;

 public:
  FenwikTree(int n) {
    arr_.assign(n + 1, 0);
    tree_.assign(n + 1, 0);
  }
  FenwikTree(std::vector<int64_t> a) : FenwikTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) {
      Update(i + 1, a[i]);
    }
  }
  int64_t Sum(size_t l, int r) { return (GetSum(r) - GetSum(l - 1)); }
  int64_t GetSum(int r) {
    int64_t ans = 0;
    for (; r >= 1; r = (r & (r + 1)) - 1) {
      ans += tree_[r];
    }
    return ans;
  }
  void Update(size_t idx, int64_t val) {
    int64_t delta = val - arr_[idx];
    arr_[idx] = val;
    UpdateDelta(idx, delta);
  }
  void UpdateDelta(size_t idx, int64_t delta) {
    for (size_t j = idx; j < tree_.size(); j |= (j + 1)) {
      tree_[j] += delta;
    }
  }
};
int main() {
  char ans;
  size_t soldiers_in_army;
  size_t query_amount;
  size_t left;
  size_t right;
  size_t idx;
  int64_t new_val;
  std::cin >> soldiers_in_army;
  std::vector<int64_t> arr(soldiers_in_army);
  for (size_t i = 0; i < soldiers_in_army; ++i) {
    std::cin >> arr[i];
  }
  FenwikTree tree(arr);
  std::cin >> query_amount;
  for (size_t i = 0; i < query_amount; ++i) {
    std::cin >> ans;
    switch (ans) {
      case 's': {
        std::cin >> left >> right;
        std::cout << tree.Sum(left, right) << std::endl;
        break;
      }
      case 'u': {
        std::cin >> idx >> new_val;
        tree.Update(idx, new_val);
      }
    }
  }
  return 0;
}