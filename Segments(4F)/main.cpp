#include <iostream>
#include <string>
#include <vector>
#define MAX_VAL 3
const int kMax = 1e6;
struct Node {
  int32_t left;
  int32_t right;
  Node() = default;
  Node(Node a, Node b) {
    left = b.left + a.left - std::min(a.left, b.right);
    right = a.right + b.right - std::min(a.left, b.right);
  }
};

std::vector<Node> tree(MAX_VAL* kMax, Node());

void Build(int32_t node, int32_t left, int32_t right, std::string& s) {
  if (left == right) {
    tree[node] = Node();
    if (s[left] == ')') {
      tree[node].right++;
    } else {
      tree[node].left++;
    }
    return;
  }
  int32_t md = (left + right) / 2;
  Build(2 * node, left, md, s);
  Build(2 * node + 1, md + 1, right, s);
  tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
}

Node Query(int32_t node, int32_t x, int32_t y, int32_t left, int32_t right) {
  if (x > right || y < left) {
    return Node();
  }
  if (x <= left && right <= y) {
    return tree[node];
  }
  int32_t md = (left + right) / 2;
  return Node(Query(2 * node, x, y, left, md),
              Query(2 * node + 1, x, y, md + 1, right));
}

int main() {
  std::string s;
  std::cin >> s;
  size_t n;
  int32_t left;
  int32_t right;
  int32_t ans;
  Node sought;
  Build(1, 0, s.size() - 1, s);
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> left >> right;
    sought = Query(1, left - 1, right - 1, 0, s.size() - 1);
    ans = (right - left + 1) - (sought.left + sought.right);
    std::cout << ans << std::endl;
  }
  return 0;
}