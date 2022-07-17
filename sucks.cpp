#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int sumOfFactors(int n)
{
  int sum = 0;

  for (int i = 1; i <= n / 2; i++)
  {
    if (n % i == 0)
    {
      sum += i;
    }
  }

  sum += n;

  return sum;
}

int vowelCount(string s)
{

  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c)
                 { return std::tolower(c); });

  char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

  int count = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (std::find(vowel, vowel + 5, s[i]) != vowel + 5)
    {
      count++;
    }
  }

  return count;
}

int _sumOfDigits(int n)
{
  return n < 10 ? n : n % 10 + _sumOfDigits(n / 10);
}

int sumOfDigits(int n)
{
  return n < 10 ? n : sumOfDigits(_sumOfDigits(n));
}

float findAverageMark(float score[7])
{
  sort(score, score + 7);
  return (score[2] + score[3] + score[4]) / 3;
}

int main()
{
  cout << sumOfFactors(24) << endl;

  string s = "I am good";
  cout << vowelCount(s) << endl;

  cout << sumOfDigits(256) << endl;

  float marks[7] = {
      80, 75, 58, 88, 90, 75, 80};
  cout << fixed << setprecision(2) << findAverageMark(marks) << endl;
}