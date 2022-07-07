#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<int32_t>> graph;
std::vector<std::vector<int32_t>> comp;
std::vector<int32_t> bank;
std::vector<bool> used;
int32_t tmp_cnt = 0;
void dfs(int32_t vert) {
  used[vert] = true;
  bank.push_back(vert);
  for (auto to : graph[vert]) {
    if (used[to]) {
      continue;
    }
    dfs(to);
    comp[tmp_cnt].push_back(to);
  }
}
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  std::cin >> vertex_num >> edge_num;
  graph.resize(vertex_num + 1);
  comp.resize(1);
  used.assign(vertex_num + 1, false);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int32_t cnt = 0;
  for (int32_t s = 1; s <= vertex_num; ++s) {
    if (!used[s]) {
      bank.clear();
      comp.push_back({});
      comp[tmp_cnt].push_back(s);
      dfs(s);
      ++tmp_cnt;
      ++cnt;
    }
  }
  std::cout << cnt << std::endl;
  for (int32_t i = 0; i < tmp_cnt; ++i) {
    std::cout << comp[i].size() << std::endl;
    for (int32_t j = 0; j < comp[i].size(); ++j) {
      std::cout << comp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
