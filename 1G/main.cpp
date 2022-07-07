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
  int Back() {
    if (el_ == nullptr || sz_ == 0) {
      throw std::invalid_argument("error");
    }
    return el_->val;
  }
  int Min() {
    if (el_ == nullptr || sz_ == 0) {
      throw std::invalid_argument("error");
    }
    return el_->min;
  }
  int Size() const { return sz_; }
  void Clear() {
    while (sz_ != 0) {
      Pop();
    }
  }
};
class MinQueue {
 private:
  Stack pushStack_, popStack_;

 public:
  void Enqueue(int val) {
    pushStack_.Push(val);
    if (popStack_.Size() == 0) {
      while (pushStack_.Size() != 0) {
        popStack_.Push(pushStack_.Pop());
      }
    }
    std::cout << "ok" << std::endl;
  }
  void Dequeue() {
    if (popStack_.Size() == 0 && pushStack_.Size() != 0) {
      while (pushStack_.Size() != 0) {
        popStack_.Push(pushStack_.Pop());
      }
    } else if (popStack_.Size() == 0 && pushStack_.Size() == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << popStack_.Pop() << std::endl;
    ;
  }
  void Front() {
    if (popStack_.Size() == 0 && pushStack_.Size() != 0) {
      while (pushStack_.Size() != 0) {
        popStack_.Push(pushStack_.Pop());
      }
    }
    if (popStack_.Size() == 0 && pushStack_.Size() == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    std::cout << popStack_.Back() << std::endl;
  }
  int Size() { return popStack_.Size() + pushStack_.Size(); }
  void Min() {
    int min;
    if (popStack_.Size() == 0 && pushStack_.Size() == 0) {
      std::cout << "error" << std::endl;
      return;
    }
    if (popStack_.Size() == 0 && pushStack_.Size() != 0) {
      min = pushStack_.Min();
    } else if (pushStack_.Size() == 0 && popStack_.Size() != 0) {
      min = popStack_.Min();
    } else {
      min = popStack_.Min() > pushStack_.Min() ? pushStack_.Min()
                                               : popStack_.Min();
    }
    std::cout << min << std::endl;
  }
  void Clear() {
    pushStack_.Clear();
    popStack_.Clear();
    std::cout << "ok" << std::endl;
  }
};
int main() {
  MinQueue head = MinQueue();
  int commands;
  int val;
  std::cin >> commands;
  std::string str;
  while (commands > 0) {
    std::cin >> str;
    if (str == "enqueue") {
      std::cin >> val;
      head.Enqueue(val);
    } else if (str == "dequeue") {
      head.Dequeue();
    } else if (str == "front") {
      head.Front();
    } else if (str == "size") {
      std::cout << head.Size() << std::endl;
    } else if (str == "min") {
      head.Min();
    } else if (str == "clear") {
      head.Clear();
    }
    --commands;
  }
}