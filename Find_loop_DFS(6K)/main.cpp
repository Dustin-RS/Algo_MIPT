#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include<unordered_set>
bool isLoop = false;
int32_t vert_num;
int32_t edge_num;
std::vector<std::unordered_set<int32_t>> graph;
std::vector<std::string> color;
std::vector<int32_t> path;
void dfs(int32_t vert) {
  if (isLoop) {
    return;
  }
  path.push_back(vert);
  color[vert] = "GRAY";
  for (int32_t to : graph[vert]) {
    if (color[to] == "GRAY") {
      isLoop = true;
      path.push_back(to);
      return;
    } else if(color[to] == "WHITE"){
      dfs(to);
    }
    if (isLoop) {
      return;
    }
  }
  color[vert] = "BLACK";
  path.pop_back();
}
int main() {
  std::cin >> vert_num >> edge_num;
  graph.resize(vert_num + 1);
  path.resize(vert_num + 1);
  color.assign(vert_num + 1, "WHITE");
  for (int32_t i = 1; i <= edge_num; ++i) {
    int32_t a;
    int32_t b;
    std::cin >> a >> b;
    graph[a].insert(b);
  }
  for (int32_t i = 1; i <= vert_num; ++i) {
    if (color[i] == "WHITE") {
      dfs(i);
      if (isLoop) {
        break;
      }
    }
  }
  if (isLoop) {
    std::cout << "YES" << std::endl;
    int32_t i = path.size() - 2;
    int32_t to = path.back();
    while (path[i] != to) {
      --i;
    }
    for (; i < path.size() - 1; ++i) {
      std::cout << path[i] << " ";
    }
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
