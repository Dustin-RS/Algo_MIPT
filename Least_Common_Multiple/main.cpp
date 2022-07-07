#include <iostream>

int NOD(long long num_a, long long num_b) {
  return num_b != 0 ? NOD(num_b, num_a % num_b) : num_a;
}

int main() {
  long long num_a;
  long long num_b;
  std::cin >> num_a >> num_b;
  long long devider = NOD(num_a, num_b);
  long long ans = num_a * num_b / devider;
  std::cout << ans;
}
