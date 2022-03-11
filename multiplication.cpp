#include <iostream>

int main() {
  for (int x = 1; x <= 12; x ++) {
    for (int y = 1; y <= 12; y ++) {
      std::cout << x << " * " << y << " = " << x * y << std::endl;
    }
    std::cout << std::endl;
  }
}