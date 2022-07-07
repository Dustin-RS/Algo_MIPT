#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_HEIGHT 10001
#define INF 1e9
int32_t col = 0;
int32_t row = 0;
std::vector<std::vector<int32_t>> graph;
std::queue<std::pair<int32_t, int32_t>> q;
std::vector<std::vector<bool>> used;
std::vector<std::pair<int32_t, int32_t>> pos_t = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void Bfs() {
  while (!q.empty()) {
    std::pair<int32_t, int32_t> vert_q = q.front();
    q.pop();
    for (std::pair<int32_t, int32_t> i : pos_t) {
      std::pair<int32_t, int32_t> vert = {vert_q.first + i.first,
                                          vert_q.second + i.second};
      if ((!used[vert.first][vert.second]) &&
          (graph[vert.first][vert.second] >=
           graph[vert_q.first][vert_q.second]) &&
          (graph[vert.first][vert.second] != MAX_HEIGHT)) {
        q.emplace(vert.first, vert.second);
        used[vert.first][vert.second] = 1;
      }
    }
  }
}

std::pair<int32_t, int32_t> NewSt() {
  int32_t min = INF;
  bool is_ex = false;
  std::pair<int32_t, int32_t> new_st = {-1, -1};
  for (size_t i = 0; i < graph.size(); ++i) {
    for (size_t j = 0; j < graph[0].size(); ++j) {
      if (!used[i][j] && graph[i][j] != MAX_HEIGHT && graph[i][j] < min) {
        new_st = {i, j};
        min = graph[i][j];
        is_ex = true;
      }
    }
  }
  if (is_ex) {
    return new_st;
  } else {
    return {-1, -1};
  }
}

int main() {
  std::cin >> row >> col;
  
  graph.assign(row + 2, std::vector<int32_t>(col + 2, MAX_HEIGHT));
  used.assign(row + 2, std::vector<bool>(col + 2, 0));
  for (int32_t i = 1; i <= row; i++) {
    for (int32_t j = 1; j <= col; j++) {
      std::cin >> graph[i][j];
    }
  }
  int32_t ans = 0;
  std::pair<int32_t, int32_t> st = NewSt();
  while (st != std::pair<int32_t,int32_t>({-1, -1})) {
    q.push(st);
    ++ans;
    used[st.first][st.second] = 1;
    Bfs();
    st = NewSt();
  }
  std::cout << ans;
  return 0;
}
