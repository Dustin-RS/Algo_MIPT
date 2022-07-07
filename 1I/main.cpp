#include <iostream>
struct Node {
  explicit Node(const int& value) : value(value) {}

  Node* next = nullptr;
  Node* prev = nullptr;
  int value;
};
class Deque {
 private:
  size_t size_;
  Node* head_;
  Node* tail_;

 public:
  Deque() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }
  ~Deque() { Clear(); }
  void PushBack(const int& value) {
    Node* new_node = new Node(value);
    if (Empty()) {
      tail_ = head_ = new_node;
    } else {
      new_node->next = head_;
      head_->prev = new_node;
      head_ = new_node;
    }
    ++size_;
  }

  void PushFront(const int& value) {
    Node* new_node = new Node(value);
    if (Empty()) {
      head_ = tail_ = new_node;
    } else {
      new_node->prev = tail_;
      tail_->next = new_node;
      tail_ = new_node;
    }
    ++size_;
  }

  int PopBack() {
    int return_value;
    if (Empty()) {
      throw;
    }
    if (Size() == 1) {
      return_value = head_->value;
      delete head_;
      head_ = tail_ = nullptr;
    } else {
      Node* prev_head = head_;
      return_value = head_->value;
      head_ = head_->next;
      delete prev_head;
      if (head_ != nullptr) {
        head_->prev = nullptr;
      }
    }
    --size_;
    return return_value;
  }
  int PopFront() {
    int return_value;
    if (Empty()) {
      throw;
    }
    if (Size() == 1) {
      return_value = head_->value;
      delete head_;
      head_ = tail_ = nullptr;
    } else {
      Node* prev_tail = tail_;
      return_value = tail_->value;
      tail_ = tail_->prev;
      delete prev_tail;
      if (tail_ != nullptr) {
        tail_->next = nullptr;
      }
    }
    --size_;
    return return_value;
  }

  bool Empty() const { return Size() == 0; }

  size_t Size() const { return size_; }

  void Clear() {
    while (!Empty()) {
      PopBack();
    }
  }
};

int main() {
  Deque push_deq = Deque();
  Deque pop_deq = Deque();
  int val;
  for (int inquiry = (std::cin >> inquiry, inquiry); inquiry > 0; --inquiry) {
    char sign = (std::cin >> sign, sign);
    switch (sign) {
      case '+':
        std::cin >> val;
        push_deq.PushBack(val);
        while (pop_deq.Size() < push_deq.Size()) {
          pop_deq.PushBack(push_deq.PopFront());
        }
        break;
      case '*':
        std::cin >> val;
        if (push_deq.Size() == pop_deq.Size()) {
          pop_deq.PushBack(val);
        } else {
          push_deq.PushFront(val);
        }
        break;
      case '-':
        std::cout << pop_deq.PopFront() << std::endl;
        while (pop_deq.Size() < push_deq.Size()) {
          pop_deq.PushBack(push_deq.PopFront());
        }
    }
  }
}