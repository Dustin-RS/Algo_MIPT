#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<int32_t>> graph;
std::vector<std::vector<int32_t>> tr_graph;
std::vector<bool> used;
std::vector<int32_t> ord;
std::vector<int32_t> compon;
std::vector<int32_t> print_comp;
void dfs_graph(int32_t vert) {
  used[vert] = true;
  for (auto to : graph[vert]) {
    if (!used[to]) {
      dfs_graph(to);
    }
  }
  ord.push_back(vert);
}
void dfs_tr_graph(int32_t vert) {
  used[vert] = true;
  compon.push_back(vert);
  for (auto to : tr_graph[vert]) {
    if (!used[to]) {
      dfs_tr_graph(to);
    }
  }
}
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  int32_t cnt = 0;
  std::cin >> vertex_num >> edge_num;
  used.assign(vertex_num + 1, false);
  graph.resize(vertex_num + 1);
  tr_graph.resize(vertex_num + 1);
  ord.resize(1);
  compon.resize(1);
  print_comp.resize(vertex_num + 1);

  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t from;
    int32_t to;
    std::cin >> from >> to;
    graph[from].push_back(to);
    tr_graph[to].push_back(from);
  }
  for (int32_t i = 1; i <= vertex_num; ++i) {
    if (used[i]) {
      continue;
    }
    dfs_graph(i);
  }
  used.assign(vertex_num + 1, false);
  for (int32_t i = 0; i < vertex_num; ++i) {
    int32_t vert = ord[vertex_num - i];
    if (used[vert]) {
      continue;
    }
    ++cnt;
    dfs_tr_graph(vert);
    for (int32_t j = 0; j < compon.size(); ++j) {
      print_comp[compon[j]] = cnt;
    }
    compon.clear();
  }
  std::cout << cnt << std::endl;
  for (int32_t i = 1; i <= vertex_num; ++i) {
    std::cout << print_comp[i] << " ";
  }

  return 0;
}
