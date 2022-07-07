#include <iostream>
#include <string>
#include <vector>
class Heap {
 private:
  using ValueType = int;
  void SiftUp(size_t index) {
    if (index <= 0 || (heap_[index] >= heap_[index / 2])) {
      return;
    }
    std::swap(heap_[index], heap_[index / 2]);
    SiftUp(index / 2);
  }
  void SiftDown(size_t index) {
    if (2 * index >= Size()) {
      return;
    }
    if (heap_[2 * index] < heap_[index]) {
      if (2 * index + 1 < Size() && heap_[2 * index] > heap_[2 * index + 1] &&
          heap_[index] > heap_[2 * index + 1]) {
        std::swap(heap_[index], heap_[2 * index + 1]);
        SiftDown(2 * index + 1);
      } else {
        std::swap(heap_[index], heap_[2 * index]);
        SiftDown(2 * index);
      }
    } else if (2 * index + 1 < Size() && heap_[2 * index + 1] < heap_[index]) {
      std::swap(heap_[index], heap_[2 * index + 1]);
      SiftDown(2 * index + 1);
    } else {
      return;
    }
  }
  std::vector<ValueType> heap_;

 public:
  void Insert(ValueType val) {
    heap_.push_back(val);
    SiftUp(heap_.size() - 1);
    std::cout << "ok" << std::endl;
  }
  ValueType ExtractMin() {
    if (heap_.empty()) {
      throw std::invalid_argument("error");
    }
    ValueType retrun_val = heap_[0];
    if (heap_.size() > 1) {
      std::swap(heap_[0], heap_[heap_.size() - 1]);
      heap_.pop_back();
      SiftDown(0);
    } else {
      heap_.pop_back();
    }
    return retrun_val;
  }
  [[nodiscard]] const ValueType& GetMin() {
    if (heap_.empty()) {
      throw std::invalid_argument("error");
    }
    return heap_[0];
  }
  [[nodiscard]] size_t Size() const { return heap_.size(); }
  void Clear() { heap_.clear(); }
  ~Heap() { Clear(); }
};
int main() {
  int query_amount;
  int val;
  std::string str;
  Heap heap;
  std::cin >> query_amount;
  for (; query_amount > 0; --query_amount) {
    std::cin >> str;
    if (str == "insert") {
      std::cin >> val;
      heap.Insert(val);
    } else if (str == "extract_min") {
      try {
        std::cout << heap.ExtractMin() << std::endl;
      } catch (...) {
        std::cout << "error" << std::endl;
      }
    } else if (str == "get_min") {
      try {
        std::cout << heap.GetMin() << std::endl;
      } catch (...) {
        std::cout << "error" << std::endl;
      }
    } else if (str == "size") {
      std::cout << heap.Size() << std::endl;
    } else if (str == "clear") {
      heap.Clear();
      std::cout << "ok" << std::endl;
    }
  }
}