#include <iostream>
#include <queue>
#include <vector>
std::vector<std::pair<int32_t,int32_t>> pos_t = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int main() {
  int32_t row;
  int32_t col;
  std::cin >> row >> col;
  std::queue<std::pair<int32_t, int32_t>> q;
  std::vector<std::vector<int32_t>> dist(
      row + 1, std::vector<int32_t>(col + 1, 1000000000));
  std::vector<std::vector<int32_t>> graph(row + 1,
                                          std::vector<int32_t>(col + 1));

  for (int32_t i = 1; i <= row; ++i) {
    for (int32_t j = 1; j <= col; ++j) {
      std::cin >> graph[i][j];
      if (graph[i][j] == 1) {
        q.push(std::pair<int32_t, int32_t>(i, j));
        dist[i][j] = 0;
      }
    }
  }
  //std::vector<int32_t> path(1, end_num);
  while (!q.empty()) {
    std::pair<int32_t, int32_t> vert_q = q.front();
    q.pop();
    for (std::pair<int32_t, int32_t> i : pos_t) {
      std::pair<int32_t, int32_t> vert = {vert_q.first + i.first,
                                          vert_q.second + i.second};
      if (vert.first > 0 && vert.first <= row && vert.second > 0 &&
          vert.second <= col &&
          dist[vert.first][vert.second] >
              dist[vert_q.first][vert_q.second] + 1) {
        dist[vert.first][vert.second] = dist[vert_q.first][vert_q.second] + 1;
        q.push(vert);
      }
    }
  }
  for (int32_t i = 1; i <= row; ++i) {
    for (int32_t j = 1; j <= col; ++j) {
      std::cout << dist[i][j] << " ";
    }
    std::cout<<std::endl;
  }
  return 0;
}
