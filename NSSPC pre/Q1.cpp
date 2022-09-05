#include <iostream>
#include <math.h>
#include <assert.h>
#include <string>

std::string sumOfEvenInRange(float a, float b)
{
    // check if a and b is positive integer
    if (std::fmod(a, 1) != 0.0 || std::fmod(b, 1) != 0.0 || a < 0 || b < 0)
    {
        return "Invalid Input";
    }

    // switch the place of a and b if needed
    if (b < a)
    {
        int t = a;
        a = b;
        b = t;
    }

    // calculate the sum of even number in the range inclusive
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            count += i;
        }
    }

    return std::to_string(count);
}

int main()
{
    assert(sumOfEvenInRange(20, 2) == "110");
    assert(sumOfEvenInRange(50, 5.5) == "Invalid Input");
    assert(sumOfEvenInRange(-4, 8) == "Invalid Input");
    assert(sumOfEvenInRange(8, 8) == "8");
    assert(sumOfEvenInRange(0, 99) == "2450");
    assert(sumOfEvenInRange(9, 9) == "0");
    assert(sumOfEvenInRange(10, -10.5) == "Invalid Input");
    assert(sumOfEvenInRange(5, 50) == "644");

    float a, b;
    std::cin >> a >> b;
    std::cout << sumOfEvenInRange(a, b) << std::endl;
}