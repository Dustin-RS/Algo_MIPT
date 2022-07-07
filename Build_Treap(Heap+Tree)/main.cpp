#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Node {
  Node(const int32_t& k_key, const int32_t& k_prior, int num)
      : key(k_key), prior(k_prior), number(num) {}
  int32_t key;
  int32_t prior;
  int32_t number;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};
bool Cmp(Node*& k_key1, Node*& k_key2) { return k_key1->key < k_key2->key; }
class Treap {
 public:
  void Build(const size_t kKKTreapSz, const std::vector<int32_t> kKKPriorArr) {
    Node* last = sorted_vector_of_keys_.front();
    for (size_t i = 1; i < kKKTreapSz; i++) {
      if (last->prior >= kKKPriorArr[i]) {
        Node* cur = last;
        while (cur->parent != nullptr &&
               cur->prior > sorted_vector_of_keys_[i]->prior) {
          cur = cur->parent;
        }
        last = sorted_vector_of_keys_[i];
        if (cur->prior <= sorted_vector_of_keys_[i]->prior) {
          last->left = cur->right;
          cur->right->parent = last;
          last->parent = cur;
          cur->right = last;
        } else {
          last->left = cur;
          cur->parent = last;
        }
      } else {
        last->right = sorted_vector_of_keys_[i];
        last->right->parent = last;
        last = last->right;
      }
    }
    while (last->parent != nullptr) {
      last = last->parent;
    }
    root_ = last;
  }
  Node* GetElementFromVector(size_t idx) { return sorted_vector_of_keys_[idx]; }
  void AddToSortedTreap(Node* node_to_add) {
    sorted_vector_of_keys_.push_back(node_to_add);
  }
  void AddToNonSortedTreap(Node* node_to_add) {
    non_sorted_vector_of_keys_.push_back(node_to_add);
  }
  void AddToVectors(Node* node_to_add) {
    AddToSortedTreap(node_to_add);
    AddToNonSortedTreap(node_to_add);
  }
  void PrintTreap(size_t treap_sz) {
    for (size_t i = 0; i < treap_sz; i++) {
      Node* cur = non_sorted_vector_of_keys_[i];
      if (cur->parent == nullptr) {
        std::cout << 0 << " ";
      } else {
        std::cout << cur->parent->number << " ";
      }
      if (cur->left == nullptr) {
        std::cout << 0 << " ";
      } else {
        std::cout << cur->left->number << " ";
      }
      if (cur->right == nullptr) {
        std::cout << 0 << " ";
      } else {
        std::cout << cur->right->number;
      }
      std::cout << std::endl;
    }
  }
  void SortTreapByKey() {
    sort(sorted_vector_of_keys_.begin(), sorted_vector_of_keys_.end(), Cmp);
  }

 private:
  Node* root_ = nullptr;
  std::vector<Node*> sorted_vector_of_keys_;
  std::vector<Node*> non_sorted_vector_of_keys_;
};
int main() {
  size_t treap_sz;
  std::cin >> treap_sz;
  int32_t key;
  int32_t prior;
  std::vector<int32_t> key_arr;
  std::vector<int32_t> prior_arr;
  std::vector<int32_t> num;
  Treap treap;
  for (size_t i = 0; i < treap_sz; ++i) {
    std::cin >> key >> prior;
    treap.AddToVectors(new Node(key, prior, i + 1));
  }
  treap.SortTreapByKey();
  for (size_t i = 0; i < treap_sz; i++) {
    key_arr.push_back(treap.GetElementFromVector(i)->key);
    prior_arr.push_back(treap.GetElementFromVector(i)->prior);
    num.push_back(treap.GetElementFromVector(i)->prior);
  }
  treap.Build(treap_sz, prior_arr);
  std::cout << "YES" << std::endl;
  treap.PrintTreap(treap_sz);
  return 0;
}