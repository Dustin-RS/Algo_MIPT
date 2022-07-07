#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<int32_t>> graph;
std::vector<int32_t> bank;
std::vector<bool> used;
void dfs(int32_t vert) {
  used[vert] = true;
  bank.push_back(vert);
  for (auto to : graph[vert]) {
    if (used[to]) {
      continue;
    }
    dfs(to);
  }
}
int main() {
  int32_t vertex_num;
  std::cin >> vertex_num;
  graph.resize(vertex_num + 1);
  used.assign(vertex_num + 1, false);
  for (int32_t i = 1; i <= vertex_num; ++i) {
    int32_t a;
    std::cin >> a;
    graph[i].push_back(a);
    graph[a].push_back(i);
  }
  int32_t cnt = 0;
  for (int32_t s = 1; s <= vertex_num; ++s) {
    if (!used[s]) {
      bank.clear();
      dfs(s);
      ++cnt;
    }
  }
  std::cout << cnt;
  return 0;
}
