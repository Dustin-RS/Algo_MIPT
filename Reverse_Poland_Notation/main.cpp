#include <iostream>
#include <string>
using namespace std;
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

void RevPolishNot(string expression) {
  Stack st = Stack();
  int tmp = 0;
  if (expression.empty()) {
    return;
  }
  for (size_t i = 0; i < expression.size(); ++i) {
    if (expression[i] == '*') {
      tmp = st.Pop() * st.Pop();
      st.Push(tmp);
    } else if (expression[i] == '-') {
      int x = st.Back();
      st.Pop();
      int y = st.Back();
      st.Pop();
      tmp = y - x;
      st.Push(tmp);
    } else if (expression[i] == '+') {
      tmp = st.Pop() + st.Pop();
      st.Push(tmp);
    } else if (expression[i] == ' ') {
      continue;
    } else {
      int x = expression[i] - '0';
      st.Push(x);
    }
  }
  cout << st.Pop();
}
int main() {
  string str;
  getline(cin, str);
  RevPolishNot(str);
  return 0;
}