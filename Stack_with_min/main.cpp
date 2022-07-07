#include <iostream>
#include <string>
typedef struct Node {
  int val;
  int min;
  struct Node* next;
} Node;
class Stack {
 private:
  Node* el_;
  int sz_;

 public:
  Stack() {
    el_ = nullptr;
    sz_ = 0;
  }
  ~Stack() { Clear(); }
  void Push(int val) {
    Node* new_node = new Node;
    int min = val;
    if (sz_ > 0) {
      if (min > el_->min) {
        min = el_->min;
      }
      new_node->val = val;
      new_node->min = min;
      new_node->next = this->el_;
      el_ = new_node;
    } else {
      new_node->val = val;
      new_node->min = val;
      new_node->next = nullptr;
      el_ = new_node;
    }
    sz_++;
    std::cout << "ok" << std::endl;
  }
  int Pop() {
    if (el_ == nullptr || sz_ == 0) {
      delete el_;
      throw std::invalid_argument("error");
    }
    int ans = el_->val;
    Node* prev_el = el_;
    el_ = prev_el->next;
    delete prev_el;
    sz_--;
    return ans;
  }
  void Back() {
    if (el_ == nullptr || sz_ == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << el_->val << std::endl;
  }
  void Min() {
    if (el_ == nullptr || sz_ == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << el_->min << std::endl;
  }
  void Size() const { std::cout << sz_ << std::endl; }
  void Clear() {
    while (sz_ != 0) {
      Pop();
    }
  }
};

int main() {
  Stack head = Stack();
  int commands;
  int val;
  std::cin >> commands;
  std::string str;
  while (commands > 0) {
    std::cin >> str;
    if (str == "push") {
      std::cin >> val;
      head.Push(val);
    } else if (str == "back") {
      head.Back();
    } else if (str == "pop") {
      try {
        std::cout << head.Pop() << std::endl;
      } catch (...) {
        std::cout << "error" << std::endl;
      }
    } else if (str == "size") {
      head.Size();
    } else if (str == "min") {
      head.Min();
    } else if (str == "clear") {
      head.Clear();
      std::cout << "ok" << std::endl;
    }
    --commands;
  }
}