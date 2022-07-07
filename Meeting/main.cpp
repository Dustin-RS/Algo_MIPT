#include <math.h>

#include <iostream>

int main() {
  double coordinate_ax;
  double coordinate_ay;
  double coordinate_bx;
  double coordinate_by;
  std::cin >> coordinate_ax >> coordinate_ay >> coordinate_bx >> coordinate_by;
  if (coordinate_ax == coordinate_bx) {
    std::printf("%.10f", coordinate_ax);
    return 0;
  }
  double len1 = ((-1) * coordinate_ay - coordinate_by);
  double len2 = (coordinate_bx - coordinate_ax);
  double coefficient = len1 / len2;
  double dist = (-1) * coefficient * coordinate_ax + coordinate_ay;
  double ans = -dist / coefficient;
  std::printf("%.10f", ans);
  return 0;
}
