#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
  float a, b, c, A, B, C;
  cin >> a >> b >> c >> A >> B >> C;

  if (a < 0 || b < 0 || c < 0 || A <= 0 || B <= 0 || C <= 0 || fmod(a + b + c + A + B + C, 1) != 0.0)
  {
    cout << "Invalid Input" << endl;
    ;
    return 0;
  }

  int m = min(a / A, min(b / B, c / C));
  printf("%d\n%d %d %d\n", m, (int)(a - A * m), (int)(b - B * m), (int)(c - C * m));
}
