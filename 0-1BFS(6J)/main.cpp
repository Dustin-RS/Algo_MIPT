#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
std::vector<std::vector<std::pair<int32_t,int32_t>>> graph;
std::vector<int32_t> dist;
std::deque<int32_t> deq;
void bfs(int32_t vert) {
  while (!deq.empty()) {
    int32_t vert = deq.front();
    deq.pop_front();
    for (auto i : graph[vert]) {
      if (dist[i.first] > dist[vert] + i.second) {
        dist[i.first] = dist[vert] + i.second;
        if (i.second == 0) {
          deq.push_front(i.first);
        } else {
          deq.push_back(i.first);
        }
      }
    }
  }
}
int main() {
  int32_t vertex_num;
  int32_t edge_num;
  int32_t rules;
  std::cin >> vertex_num >> edge_num;
  graph.resize(vertex_num + 1);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t from;
    int32_t to;
    std::cin >> from >> to;
    graph[from].push_back({to, 0});
    graph[to].push_back({from, 1});
  }
  std::cin >> rules;
  for (int32_t i = 1; i <= rules; ++i) {
    int32_t from;
    int32_t to;
    std::cin>>from>>to;
    dist.assign(vertex_num + 1, 5001);
    deq.clear();
    dist[from] = 0;
    deq.push_back(from);
    bfs(from);
    if (dist[to] == 5001) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << dist[to] << std::endl;
    }
  }
  return 0;
}
