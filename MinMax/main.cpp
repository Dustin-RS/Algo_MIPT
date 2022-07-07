#include <iostream>
#include <vector>
class MinMax {
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
  size_t FindMaximumElement() {
    ValueType maximum_element = heap_[Size() / 2];
    size_t max_idx = 0;
    for (size_t i = Size() / 2; i < Size(); ++i) {
      maximum_element = std::max(maximum_element, heap_[i]);
      if (maximum_element == heap_[i]) {
        max_idx = i;
      }
    }
    return max_idx;
  }
  std::vector<ValueType> heap_;

 public:
  void Insert(ValueType val) {
    heap_.push_back(val);
    SiftUp(Size() - 1);
    std::cout << "ok" << std::endl;
  }

  ValueType ExtractMin() {
    if (heap_.empty()) {
      std::cout << "error" << std::endl;
      throw std::invalid_argument("error");
    }
    ValueType minimum = heap_[0];
    if (Size() == 1) {
      heap_.pop_back();
    } else {
      std::swap(heap_[0], heap_[Size() - 1]);
      heap_.pop_back();
      SiftDown(0);
    }
    return minimum;
  }

  ValueType ExtractMax() {
    if (heap_.empty()) {
      std::cout << "error" << std::endl;
      throw std::invalid_argument("error");
    }
    size_t maximum_idx = FindMaximumElement();
    int ret_val = heap_[maximum_idx];
    for (size_t i = Size() / 2; i < Size(); ++i) {
      if (i == maximum_idx) {
        std::swap(heap_[i], heap_[Size() - 1]);
        SiftUp(i);
      }
    }
    heap_.pop_back();
    return ret_val;
  }

  [[nodiscard]] ValueType& GetMin() {
    if (heap_.empty()) {
      std::cout << "error" << std::endl;
      throw std::invalid_argument("error");
    }
    return heap_[0];
  }

  [[nodiscard]] ValueType GetMax() {
    if (heap_.empty()) {
      std::cout << "error" << std::endl;
      throw std::invalid_argument("error");
    }
    ValueType maximum_element = heap_[Size() / 2];
    for (size_t i = Size() / 2; i < Size(); ++i) {
      maximum_element = std::max(maximum_element, heap_[i]);
    }
    return maximum_element;
  }

  [[nodiscard]] size_t Size() const { return heap_.size(); }

  void Clear() {
    heap_.clear();
    std::cout << "ok" << std::endl;
  }
  [[nodiscard]] bool Empty() { return heap_.empty(); }
};
void Conditions(std::string str, MinMax& heap, int val) {
  if (str == "insert") {
    std::cin >> val;
    heap.Insert(val);
  } else if (str == "extract_max") {
    try {
      std::cout << heap.ExtractMax() << std::endl;
    } catch (...) {
    }
  } else if (str == "get_max") {
    try {
      std::cout << heap.GetMax() << std::endl;
    } catch (...) {
    }
  } else if (str == "extract_min") {
    try {
      std::cout << heap.ExtractMin() << std::endl;
    } catch (...) {
    }
  } else if (str == "get_min") {
    try {
      std::cout << heap.GetMin() << std::endl;
    } catch (...) {
    }
  } else if (str == "size") {
    std::cout << heap.Size() << std::endl;
  } else if (str == "clear") {
    heap.Clear();
  }
}
int main() {
  int query_amount;
  int val = 0;
  std::string str;
  MinMax heap;
  std::cin >> query_amount;
  for (; query_amount > 0; --query_amount) {
    std::cin >> str;
    Conditions(str, heap, val);
  }
  return 0;
}