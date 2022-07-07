#include <iostream>
#include <queue>
#include <vector>
std::vector<std::pair<int32_t, int32_t>> pos_vert(
    {{1, -2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}});
  int main() {
  int32_t vert_num;
  std::pair<int32_t, int32_t> beg_p;
  std::pair<int32_t, int32_t> end_p;
  std::queue<std::pair<int32_t, int32_t>> q;
  std::cin >> vert_num >> beg_p.first >> beg_p.second >> end_p.first >> end_p.second;
  std::vector<std::vector<std::pair<int32_t, int32_t>>> prev(
      vert_num + 1, std::vector<std::pair<int32_t, int32_t>>(vert_num + 1));
  std::vector<std::pair<int32_t, int32_t>> path(1, end_p);
  std::vector<std::vector<int32_t>> dist(vert_num + 1,
                                         std::vector<int32_t>(vert_num + 1, 1000000000));
  dist[beg_p.first][beg_p.second] = 0;
  prev[beg_p.first][beg_p.second] = {-1, -1};
  q.push(beg_p);
  while (!q.empty()) {
    std::pair<int32_t, int32_t> vert_q = q.front();
    q.pop();
    for (std::pair<int32_t, int32_t> i : pos_vert) {
      std::pair<int32_t, int32_t> vert = {vert_q.first + i.first,
                                          vert_q.second + i.second};
      if (vert.first > 0 && vert.first <= vert_num && vert.second > 0 && vert.second <= vert_num &&
          dist[vert.first][vert.second] > dist[vert_q.first][vert_q.second] + 1) {
        q.push(vert);
        prev[vert.first][vert.second] = vert_q;
        dist[vert.first][vert.second] = dist[vert_q.first][vert_q.second] + 1;
      }
    }
  }
  std::cout << dist[end_p.first][end_p.second]<<std::endl;
  while (prev[end_p.first][end_p.second] !=
         std::pair<int32_t, int32_t>({-1, -1})) {
    end_p = prev[end_p.first][end_p.second];
    path.push_back(end_p);
  }
  for (int32_t i = static_cast<int32_t>(path.size()) - 1; i >= 0; --i) {
    std::cout << path[i].first << " " << path[i].second<<std::endl;
  }
  return 0;
}
