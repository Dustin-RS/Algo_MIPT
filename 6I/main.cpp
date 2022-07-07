#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
int main() {
  uint16_t vertex_num;
  int32_t edge_num;
  uint16_t start;
  uint16_t finish;
  std::cin >> vertex_num >> edge_num >> start >> finish;
  std::vector<std::queue<uint16_t>> q(30 * vertex_num, std::queue<uint16_t>());
  std::vector<int32_t> dist(vertex_num + 1, 50 * 10e3 + 1);
  std::vector<bool> used(vertex_num + 1, false);
  std::vector<std::vector<std::pair<uint16_t, int16_t>>> graph(
      vertex_num + 1, std::vector<std::pair<uint16_t, int16_t>>{});
  for (int32_t i = 1; i <= edge_num; ++i) {
    uint16_t a;
    uint16_t b;
    int16_t w;
    std::cin >> a >> b >> w;
    graph[a].push_back({b,w});
  }
  dist[start] = 0;
  q[0].push(start);
  for (int32_t d = 0; d < 30 * vertex_num; ++d) {
    while (!q[d].empty()) {
      uint16_t vert = q[d].front();
      q[d].pop();
      if (used[vert]) {
        continue;
      }
      used[vert] = true;
      for (auto e : graph[vert]) {
        if (!used[e.first] && dist[e.first] > dist[vert]+e.second){
          dist[e.first] = dist[vert] + e.second;
          q[dist[e.first]].push(e.first);
        }
      }
    }
  }
  if (dist[finish] == (50 * 10e3 + 1)) {
    std::cout << -1;
  } else {
    std::cout << dist[finish];
  }
  return 0;
}
