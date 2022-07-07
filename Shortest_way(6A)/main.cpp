#include <iostream>
#include <queue>
#include <vector>

int32_t vert_num;
int32_t edge_num;
int32_t beg_vert;
int32_t end_vert;
std::vector<int32_t> dist;
std::vector<int32_t> prev;
std::vector<int32_t> path;
std::queue<int32_t> q;

class Graph {
 public:
  Graph(int32_t v_num) {
    vert_num_ = v_num;
    graph_.resize(vert_num_ + 1);
  }
  Graph() { graph_.resize(1); }
  void AddEdge(int32_t v1, int32_t v2) {
    graph_[v1].push_back(v2);
    graph_[v2].push_back(v1);
  }
  std::vector<int32_t> operator[](int32_t num) { return graph_[num]; }

 private:
  int32_t vert_num_;
  std::vector<std::vector<int32_t>> graph_;
};

void Bfs(Graph& graph) {
  while (!q.empty()) {
    int32_t vert = q.front();
    q.pop();
    for (int32_t to : graph[vert]) {
      if (dist[to] == -1) {
        dist[to] = dist[vert] + 1;
        prev[to] = vert;
        q.push(to);
      }
    }
  }
  if (dist[end_vert] == -1) {
    std::cout << -1;
  } else {
    std::cout << dist[end_vert] << std::endl;
    while (prev[end_vert] != -1) {
      end_vert = prev[end_vert];
      path.push_back(end_vert);
    }
    for (int32_t i = static_cast<int32_t>(path.size()) - 1; i >= 0; --i) {
      std::cout << path[i] << " ";
    }
  }
}

int main() {
  std::cin >> vert_num >> edge_num >> beg_vert >> end_vert;
  Graph graph(vert_num);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    graph.AddEdge(a, b);
  }

  dist.assign(vert_num + 1, -1);
  prev.resize(vert_num + 1);
  path.assign(1, end_vert);
  dist[beg_vert] = 0;
  prev[beg_vert] = -1;
  q.push(beg_vert);

  Bfs(graph);
  return 0;
}
