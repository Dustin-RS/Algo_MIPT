#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
std::vector<std::vector<int32_t>> graph;
std::map<std::pair<int32_t, int32_t>, int32_t> edges;
std::vector<int32_t> tin;
std::vector<int32_t> tup;
std::vector<bool> used;
std::set<int32_t> bridge;
std::vector<int32_t> sorted_bridge;
int32_t timer = 0;
bool isEven = false;
void dfs(int32_t vert, int32_t p = -1) {
  used[vert] = true;
  tup[vert] = tin[vert] = timer++;
  for (auto to : graph[vert]) {
    if (p == to) {
      continue;
    }
    if (used[to]) {
      tup[vert] = std::min(tin[to], tup[vert]);
    } else {
      dfs(to, vert);
      tup[vert] = std::min(tup[to], tup[vert]);
      if (tin[vert] < tup[to]) {
        int32_t cnt = 0;
        for (auto to1 : graph[vert]) {
          if (to1 == to) {
            ++cnt;
          }
        }
        if (cnt == 1) {
          if (vert > to) {
            bridge.insert(edges[{to, vert}]);
          } else if (vert <= to) {
            bridge.insert(edges[{vert, to}]);
          }
        }
      }
    }
    isEven = false;
  }
}
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  std::cin >> vertex_num >> edge_num;
  graph.resize(vertex_num + 1);
  tin.resize(vertex_num + 1);
  tup.resize(vertex_num + 1);
  used.assign(vertex_num + 1, false);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    if (a > b) {
      edges[{b, a}] = i;
    } else {
      edges[{a, b}] = i;
    }
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int32_t i = 1; i <= vertex_num; ++i) {
    if (used[i]) {
      continue;
    }
    dfs(i);
  }
  std::cout << bridge.size() << std::endl;
  for (auto i = bridge.begin(); i != bridge.end(); ++i) {
    sorted_bridge.push_back(*i);
  }
  std::sort(sorted_bridge.begin(), sorted_bridge.end());
  for (int32_t i = 0; i < sorted_bridge.size(); ++i) {
    std::cout << sorted_bridge[i] << std::endl;
  }
  return 0;
}
