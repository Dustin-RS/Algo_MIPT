#include <iostream>
#include <queue>
#include <vector>
int32_t f1(int32_t num) {
  if (num / 1000 != 9) {
    num += 1000;
  }
  return num;
}
int32_t f2(int32_t num) {
  if (num % 10 != 1) {
    num -= 1;
  }
  return num;
}
int32_t f3(int32_t num) {
  num = (num / 10) + (num % 10) * 1000;
  return num;
}
int32_t f4(int32_t num) {
  num = (num / 1000) + (num % 1000) * 10;
  return num;
}
int32_t (*func[4])(int32_t) = {f1, f2, f3, f4};
int main() {
  int32_t beg_num;
  int32_t end_num;
  std::queue<int32_t> q;
  std::cin >> beg_num >> end_num;
  std::vector<int32_t> prev(10000);
  std::vector<int32_t> used(10000,0);
  std::vector<int32_t> path(1, end_num);
  q.push(beg_num);
  while (!q.empty()) {
    int32_t vert_q = q.front();
    q.pop();
    for (int32_t i = 0; i < 4; ++i) {
      if (vert_q != end_num) {
        int32_t vert = func[i](vert_q);
        if (!used[vert]) {
          used[vert] = true;
          prev[vert] = vert_q;
          q.push(vert);
        }
      } else {
        break;
      }
    }
  }
  prev[beg_num] = -1;
  while (prev[end_num] != -1) {
    end_num = prev[end_num];
    path.push_back(end_num);
  }
  std::cout << path.size() << std::endl;
  for (int32_t i = static_cast<int32_t>(path.size()) - 1; i >= 0; --i) {
    std::cout << path[i] << std::endl;
  }
  return 0;
}
