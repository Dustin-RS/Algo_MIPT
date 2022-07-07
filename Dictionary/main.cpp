#include <iostream>
#include <string>
struct Node {
  Node() = default;
  Node(const std::string& k_key, const std::string& k_synonym)
      : key(k_key), synonym(k_synonym) {}
  Node* left = nullptr;
  Node* right = nullptr;
  size_t size = 1;
  std::string key;
  std::string synonym;
};
class AvlTree {
 public:
  ~AvlTree() { Clear(root_); }
  static size_t Size(Node* cur) { return cur == nullptr ? 0 : cur->size; }
  static int DeltaBal(Node* cur) { return Size(cur->right) - Size(cur->left); }
  static Node* LeftRotate(Node* cur) {
    Node* newhead = cur->right;
    cur->right = newhead->left;
    newhead->left = cur;
    cur->size = 1 + std::max(Size(cur->left), Size(cur->right));
    newhead->size = 1 + std::max(Size(newhead->left), Size(newhead->right));
    return newhead;
  }
  static Node* RightRotate(Node* cur) {
    Node* newhead = cur->left;
    cur->left = newhead->right;
    newhead->right = cur;
    cur->size = 1 + std::max(Size(cur->left), Size(cur->right));
    newhead->size = 1 + std::max(Size(newhead->left), Size(newhead->right));
    return newhead;
  }
  static Node* Balance(Node* cur) {
    cur->size = (Size(cur->left) > Size(cur->right) ? Size(cur->left)
                                                    : Size(cur->right)) +
                1;
    if (DeltaBal(cur) >= 2) {
      DeltaBal(cur->right) < 0 ? cur->right = RightRotate(cur->right)
                               : cur->right = cur->right;
      return LeftRotate(cur);
    }
    if (DeltaBal(cur) <= -2) {
      DeltaBal(cur->left) > 0 ? cur->left = LeftRotate(cur->left)
                              : cur->left = cur->left;
      return RightRotate(cur);
    }
    return cur;
  }
  static Node* Find(Node* cur, const std::string& key) {
    if (cur == nullptr) {
      return nullptr;
    }
    return key == cur->key ? cur
                           : (key < cur->key ? Find(cur->left, key)
                                             : Find(cur->right, key));
  }
  static Node* Insert(Node* cur, const std::string& k_key,
                      const std::string& k_syn) {
    if (cur == nullptr) {
      Node* ans = new Node(k_key, k_syn);
      return ans;
    }
    k_key < cur->key ? cur->left = Insert(cur->left, k_key, k_syn)
                     : cur->right = Insert(cur->right, k_key, k_syn);
    return Balance(cur);
  }
  void Insert(const std::string& k_key, const std::string& k_syn) {
    root_ = Insert(root_, k_key, k_syn);
    root_ = Insert(root_, k_syn, k_key);
  }
  Node* Find(const std::string& key) { return Find(root_, key); }
  static void Clear(Node* node) {
    if (node != nullptr) {
      if (node->left != nullptr) {
        Clear(node->left);
      }
      if (node->right != nullptr) {
        Clear(node->right);
      }
      delete node;
    }
  }
  void Clear() { Clear(root_); }

 private:
  Node* root_ = nullptr;
};
int main() {
  AvlTree b;
  size_t syn_amount;
  size_t i = 0;
  std::cin >> syn_amount;
  std::string word;
  std::string syn;
  while (i < syn_amount) {
    std::cin >> word >> syn;
    b.Insert(word, syn);
    ++i;
  }
  size_t quer_dic;
  std::cin >> quer_dic;
  std::string find_word;
  while (quer_dic > 0) {
    std::cin >> find_word;
    std::cout << b.Find(find_word)->synonym << std::endl;
    --quer_dic;
  }
}