#include <iostream>

using namespace std;

int _sumOfDigits(int n)
{
  return n < 10 ? n : n % 10 + _sumOfDigits(n / 10);
}

int sumOfDigits(int n)
{
  return n < 10 ? n : sumOfDigits(_sumOfDigits(n));
}

int main() {
  int n;
  cin >> n;
  cout << sumOfDigits(n);
}