#include <iostream>
#include <queue>
#include <vector>
int32_t vert_num;
int32_t edge_num;
std::vector<std::vector<int32_t>> graph;
std::vector<int32_t> color;
std::vector<int32_t> parent;
bool isDoubl = true;
void dfs(int vert, int col = -1) {
  if (!isDoubl) {
    return;
  }
  color[vert] = col;
  for (int32_t to : graph[vert]) {
    if (!color[to]) {
      dfs(to, 3 - col);
    } else {
      if (color[vert] == color[to]) {
        isDoubl = false;
      }
    }
  }

}
int main() {
  std::cin >> vert_num >> edge_num;
  graph.resize(vert_num + 1);
  color.assign(vert_num + 1, 0);
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int32_t i = 1; i <= vert_num; ++i) {
    if (!color[i]) {
      dfs(i, 1);
    }
  }
  if (isDoubl) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl; 
  }
  return 0;
}
