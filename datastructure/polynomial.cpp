#include <iostream>
#include <cstdio>
#include <list>

struct Poly {
  int coef;
  int x;
  int y;
};

int main() {
  Poly p1[5] = {
    {3, 3, 2},
    {2, 2, 3},
    {7, 2, 2},
    {-3, 1, 0},
    {5, 0, 0}
  };
  std::list<Poly> polyList1;
  for (int i = 0; i < 5; i++) {
    polyList1.push_back(p1[i]);
  }

  Poly p2[6] = {
    {2, 4, 2},
    {9, 3, 2},
    {-2, 2, 1},
    {6, 1, 0},
    {-3, 0, 1},
    {-9, 0, 0}
  };
  
  std::list<Poly> polyList2;
  for (int i = 0; i < 6; i++) {
    polyList2.push_back(p2[i]);
  }
  
  for (std::list<Poly>::iterator it = polyList1.begin(); it != polyList1.end(); it++) {
    for (std::list<Poly>::iterator it2 = polyList2.begin(); it2 != polyList2.end(); it2++) {
      if (it->x == it2->x && it->y == it2->y) {
        it->coef += it2->coef;
        polyList2.erase(it2);
        break;
      }
    }
  }
  polyList1.merge(polyList2, [] (const Poly &a, const Poly &b) {
    return a.x>b.x;
  });

  polyList1.sort([] (const Poly &a, const Poly &b) {
    if (a.x > b.x) return true;
    if (a.x == b.x) {
      if (a.y > b.y) return true;
      return (a.coef < b.coef);
    }

    return false;
  });

  for (std::list<Poly>::iterator it = polyList1.begin(); it != polyList1.end(); it++) {
    std::printf("%dx^%dy^%d\n", it->coef, it->x, it->y);
  }

  return 0;
}