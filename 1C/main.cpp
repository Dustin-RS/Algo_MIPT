#include <iostream>
#define ODD_BEGIN 3
#define EVEN_BEGIN 2
int main() {
  int divider;
  int num_factorize;
  int num_nature;
  int tmp;
  short shift;
  std::cin >> num_factorize;
  while (num_factorize-- != 0) {
    std::cin >> num_nature;
    divider = num_nature % EVEN_BEGIN != 0 ? ODD_BEGIN : EVEN_BEGIN;
    shift = divider - 1;
    tmp = num_nature;
    while (num_nature > 1) {
      while (num_nature % divider == 0) {
        std::cout << divider << ' ';
        num_nature /= divider;
      }
      divider += shift;
      if (num_nature % 2 != 0) {
        shift = 2;
      }
      if (divider * divider > tmp && num_nature != 1) {
        std::cout << num_nature;
        break;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}