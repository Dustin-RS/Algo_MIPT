#include <inttypes.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <random>
#include <vector>
class HashMap {
 public:
  void Insert(int32_t data) {
    int32_t buck_idx = HashFunction(data);
    row_[buck_idx].push_back(data);
  }
  bool Contains(int32_t data) {
    int64_t buck_idx = HashFunction(data);
    auto list_buck = row_[buck_idx];
    std::list<int32_t>::iterator res_iter =
        std::find(list_buck.begin(), list_buck.end(), data);
    return res_iter != list_buck.end();
  }
  void Erase(int32_t data) {
    int64_t buck_idx = HashFunction(data);
    if (!Contains(data)) {
      return;
    }
    row_[buck_idx].remove(data);
  }
  HashMap(int32_t sz) { row_.resize(sz); }

 private:
  std::vector<std::list<int32_t>> row_{};
  const int32_t kKKPrimeLg = 9931;
  const int32_t kA = rand() % 10 + 1;
  const int32_t kB = rand() % 10 + 1;
  int32_t HashFunction(int32_t value) {
    int32_t m = static_cast<int32_t>(row_.size());
    int32_t hash = ((kA * value + kB) % kKKPrimeLg + m) % m;
    return hash;
  }
};
int main() {
  char inp;
  int32_t query;
  int32_t n;
  std::cin >> query;
  HashMap ht(query);
  while (query != 0) {
    std::cin >> inp >> n;
    switch (inp) {
      case '+': {
        ht.Insert(n);
        break;
      }
      case '-': {
        ht.Erase(n);
        break;
      }
      case '?': {
        std::cout << (ht.Contains(n) ? "YES" : "NO") << std::endl;
        break;
      }
    }
    --query;
  }
  return 0;
}