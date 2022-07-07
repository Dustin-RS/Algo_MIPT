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
    std::list<int32_t>::iterator resIter =
        std::find(list_buck.begin(), list_buck.end(), data);
    return resIter != list_buck.end();
  }
  void Erase(int32_t data) {
    int64_t buck_idx = HashFunction(data);
    if (!Contains(data)) {
      return;
    } else {
      row_[buck_idx].remove(data);
    }
  }
  HashMap(int32_t sz) { 
    row_.resize(sz); 
  }

 private:
  std::vector<std::list<int32_t>> row_{};
  const int32_t kPrimeLg_ = 9931;
  const int32_t a_ = rand() % 10 + 1;
  const int32_t b_ = rand() % 10 + 1;
  int32_t HashFunction(int32_t value) {
    int32_t m = static_cast<int32_t>(row_.size());
    int32_t hash = ((a_ * value + b_) % kPrimeLg_ + m) % m;
    return hash;
  }
};
int main() {
  char inp;
  int32_t query;
  int32_t N;
  std::cin >> query;
  HashMap ht(query);
  while (query != 0) {
    std::cin >> inp >> N;
    switch (inp) {
      case '+': {
        ht.Insert(N);
        break;
      }
      case '-': {
        ht.Erase(N);
        break;
      }
      case '?': {
        std::cout << (ht.Contains(N) ? "YES" : "NO") << std::endl;
        break;
      }
    }
    --query;
  }
  return 0;
}