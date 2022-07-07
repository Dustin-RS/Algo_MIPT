#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
struct Edge {
  int32_t to;
  int32_t weight;
  Edge(int32_t t, int32_t w) {
    to = t;
    weight = w;
  }
  Edge() = default;
};
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  int32_t start;
  int32_t finish;
  std::cin >> vertex_num >> edge_num >> start >> finish;
  std::vector<std::queue<int32_t>> q(10 * vertex_num + 1);
  std::vector<int32_t> dist(vertex_num + 1, 10001);
  std::vector<int32_t> used(vertex_num + 1, false);
  std::vector<std::vector<Edge>> graph(
      vertex_num + 1, std::vector<Edge>(vertex_num + 1));
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    int32_t w;
    std::cin >> a >> b >> w;
    Edge tmp(b, w);
    graph[a].push_back(tmp);
  }
  dist[start] = 0;
  q[0].push(start);
  for (int32_t d = 0; d <= 10 * vertex_num; ++d) {
    while (!q[d].empty()) {
      int32_t vert = q[d].front();
      q[d].pop();
      if (used[vert]) {
        continue;
      }
      used[vert] = true;
      for (Edge& e : graph[vert]) {
        int32_t to = e.to;
        if (dist[to] <= dist[vert] + e.weight) {
          continue;
        }
        dist[to] = dist[vert] + e.weight;
        q[dist[to]].push(to);
      }
    }
  }
  if (dist[finish] == 10001) {
    std::cout << -1;
  } else {
    std::cout << dist[finish];
  }
  return 0;
}
