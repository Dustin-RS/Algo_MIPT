#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<int32_t>> graph;
std::vector<int32_t> tin;
std::vector<int32_t> tup;
std::vector<bool> used;
std::unordered_set<int32_t> cut_point;
std::vector<int32_t> sorted_cut_points;
int32_t timer = 0;
void dfs(int32_t vert, int32_t p = -1) {
  used[vert] = true;
  tup[vert] = tin[vert] = timer++;
  int32_t children = 0;
  for (auto to : graph[vert]) {
    if (p == to) {
      continue;
    }
    if (used[to]) {
      tup[vert] = std::min(tin[to], tup[vert]);
    } else {
      dfs(to, vert);
      tup[vert] = std::min(tup[to], tup[vert]);
      if (tin[vert] <= tup[to] && p != -1) {
        cut_point.insert(vert);
      }
      ++children;
    }
  }
  if (p == -1 && children > 1) {
    cut_point.insert(vert);
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
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int32_t i = 1; i <= vertex_num; ++i) {
    if (used[i]) {
      continue;
    }
    dfs(i);
  }
  std::cout << cut_point.size() << std::endl;
  for (auto i = cut_point.begin(); i != cut_point.end(); ++i) {
    sorted_cut_points.push_back(*i);
  }
  std::sort(sorted_cut_points.begin(), sorted_cut_points.end());
  for (int32_t i = 0; i < sorted_cut_points.size(); ++i) {
    std::cout << sorted_cut_points[i] <<std::endl;
  }
  return 0;
}
