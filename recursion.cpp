#include <iostream>

int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

long fibo(long n) {
  if (n == 0 || n == 1) return n;
  return fibo(n - 1) + fibo(n - 2);
}

// basically just a sum version of factorial function
long sum(long n) {
  if (n == 0) {
    return 0;
  }
  return n + sum(n - 1);
}

int main() {
  // std::cout << factorial(5) << std::endl; // 1*2*3*4*5 = 120
  // std::cout << fibo(10) << std::endl; // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
  std::cout << sum(10) << std::endl; // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
  return 0;
}