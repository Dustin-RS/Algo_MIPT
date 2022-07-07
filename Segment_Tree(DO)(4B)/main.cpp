#include <iostream>
#include <vector>
struct Node {
  uint64_t val;
  uint64_t promise;
  size_t left;
  size_t right;
};
uint64_t NextPowerOf2(unsigned int n) {
  uint64_t count = 0;
  if (n != 0 && ((n & (n - 1)) == 0)) {
    return n;
  }

  while (n != 0) {
    n >>= 1;
    count += 1;
  }

  return 1 << count;
}
class SegmentTree {
 private:
  std::vector<Node> arr_;

 public:
  SegmentTree(std::vector<Node> inp_arr) {
    size_t sz = inp_arr.size();
    size_t j = 0;
    size_t new_sz = NextPowerOf2(sz);
    arr_.assign(2 * new_sz, {0, 0, 0, 0});
    for (size_t i = new_sz; i < new_sz + sz; ++i) {
      arr_[i] = {inp_arr[j].val, 0, i - new_sz + 1, i - new_sz + 2};
      ++j;
    }
    for (size_t i = new_sz + sz; i < 2 * new_sz; ++i) {
      arr_[i] = {0, 0, i - new_sz + 1, i - new_sz + 2};
    }
    for (size_t i = new_sz - 1; i > 0; --i) {
      arr_[i] = {0, 0, arr_[2 * i].left, arr_[2 * i + 1].right};
    }
  }
  uint64_t Query(size_t left, size_t right, size_t idx) {
    if (arr_[idx].right <= left || arr_[idx].left >= right) {
      return 0;
    }
    if (arr_[idx].left >= left && arr_[idx].right <= right) {
      if (arr_[idx].promise == 0) {
        return arr_[idx].val;
      }
      if (arr_[idx].promise != 0) {
        arr_[idx].val += arr_[idx].promise;
        arr_[idx].promise = 0;
      }
      return arr_[idx].val;
    }
    arr_[idx * 2].promise += arr_[idx].promise;
    arr_[idx * 2 + 1].promise += arr_[idx].promise;
    arr_[idx].promise = 0;
    return Query(left, right, idx * 2) + Query(left, right, idx * 2 + 1);
  }
  uint64_t GetElement(size_t idx) { return Query(idx, idx + 1, 1); }
  void Update(size_t left, size_t right, uint64_t promise, size_t idx = 1) {
    if (arr_[idx].right <= left || arr_[idx].left >= right) {
      return;
    }
    if (arr_[idx].left >= left && arr_[idx].right <= right) {
      arr_[idx].promise += promise;
      return;
    }
    Update(left, right, promise, idx * 2);
    Update(left, right, promise, idx * 2 + 1);
  }
};
int main() {
  char ans;
  size_t inp_sz;
  size_t query_amount;
  uint64_t idx;
  uint64_t left;
  uint64_t right;
  uint64_t add;
  std::cin >> inp_sz;
  std::vector<Node> inp_arr(inp_sz);
  for (size_t i = 0; i < inp_sz; ++i) {
    std::cin >> inp_arr[i].val;
  }
  SegmentTree tree(inp_arr);
  std::cin >> query_amount;
  for (size_t i = 0; i < query_amount; ++i) {
    std::cin >> ans;
    if (ans == 'g') {
      std::cin >> idx;
      std::cout << tree.GetElement(idx) << std::endl;
    } else if (ans == 'a') {
      std::cin >> left >> right >> add;
      tree.Update(left, right + 1, add);
    }
  }
  return 0;
}