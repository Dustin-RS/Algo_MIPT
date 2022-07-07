#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define HALF 2.0
struct Point {
  int64_t x;
  int64_t y;
  Point(int64_t x = 0, int64_t y = 0) {
    this->x = x;
    this->y = y;
  }
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  long double operator^(Point p) const {
    return static_cast<long double>(x * p.y - y * p.x);
  }
  bool operator!=(Point p) const { return (x != p.x || y != p.y); }
  int64_t Length() const { return x * x + y * y; }
};
Point beg_point;
bool operator<(Point point1, Point point2) {
  point1 = point1 - beg_point;
  point2 = point2 - beg_point;
  return (point1 ^ point2) != 0 ? ((point1 ^ point2) > 0)
                                : point1.Length() < point2.Length();
}
long double PolygSquare(std::vector<Point> polygon) {
  long double area = 0.0;
  Point fix_point = polygon[0];
  for (size_t i = 1; i < polygon.size() - 1; ++i) {
    area +=
        std::abs((static_cast<long double>(((polygon[i] - fix_point) ^
                                            (polygon[i + 1] - fix_point)))) /
                 HALF);
  }
  return (area);
}
void OutData(std::vector<Point> polyg_coord) {
  std::cout << polyg_coord.size() << std::endl;
  std::cout << polyg_coord[0].x << " " << polyg_coord[0].y << std::endl;
  for (int64_t i = polyg_coord.size() - 1; i > 0; --i) {
    std::cout << polyg_coord[i].x << " " << polyg_coord[i].y << std::endl;
  }
  std::cout << std::fixed << std::setprecision(1) << PolygSquare(polyg_coord)
            << std::endl;
}
void SetBegPoint(int64_t point_am, std::vector<Point> field) {
  beg_point = field[0];
  for (int64_t i = 1; i < point_am; ++i) {
    if (beg_point.x > field[i].x) {
      beg_point = field[i];
    }
    if (beg_point.x == field[i].x && beg_point.y > field[i].y) {
      beg_point = field[i];
    }
  }
}
int main() {
  int64_t point_am;
  std::cin >> point_am;
  std::vector<Point> field(point_am);
  std::vector<Point> polyg_coord;
  for (int64_t i = 0; i < point_am; ++i) {
    std::cin >> field[i].x >> field[i].y;
  }
  SetBegPoint(point_am, field);
  std::sort(field.begin(), field.end());
  polyg_coord.push_back(field[0]);
  for (int64_t i = 1; i < point_am; ++i) {
    while (polyg_coord.size() > 1) {
      if (((polyg_coord[polyg_coord.size() - 1] -
            polyg_coord[polyg_coord.size() - 2]) ^
           (field[i] - polyg_coord[polyg_coord.size() - 1])) <= 0) {
        polyg_coord.pop_back();
      } else {
        break;
      }
    }
    polyg_coord.push_back(field[i]);
  }
  OutData(polyg_coord);
}