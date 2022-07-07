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
bool CorBracketSequence(string expression) {
  Stack st = Stack();
  int tmp = 0;
  if (expression.empty()) {
    return true;
  }
  for (size_t i = 0; i < expression.size(); ++i) {
    if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
      st.Push(expression[i]);
      continue;
    }
    switch (expression[i]) {
      case ')':
        tmp = st.Pop();
        return !(tmp == '{' || tmp == '[');
        break;
      case '}':
        tmp = st.Pop();
        return !(tmp == '(' || tmp == '[');
        break;
      case ']':
        tmp = st.Pop();
        return !(tmp == '(' || tmp == '{');
        break;
    }
    return !(st.Size() == 0);
  }
  return st.Size() == 0;
}
int main() {
  string str;
  getline(cin, str);
  string ans = CorBracketSequence(str) ? "YES" : "NO";
  std::cout << ans << std::endl;
  return 0;
}