#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<int32_t>> graph;
std::vector<int32_t> path;
std::vector<int16_t> color;
void dfs(int32_t vert) {
  color[vert] = 1;
  for (auto to : graph[vert]) {
    if (color[to] == 1) {
      std::cout << -1;
      exit(0);
    } else if (color[to] == 2) {
      continue;
    }
    else {
      dfs(to);
    }
  }
  path.push_back(vert);
  color[vert] = 2;
}
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  std::cin >> vertex_num >> edge_num;
  graph.resize(vertex_num + 1);
  color.assign(vertex_num + 1, 0);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    graph[a].push_back(b);
  }
  for (int32_t s = 1; s <= vertex_num; ++s) {
    if (color[s] == 0) {
      dfs(s);
    }
  }
  for (int32_t i = path.size() - 1; i >= 0; --i) {
    std::cout << path[i] << " ";
  }
  return 0;
}
