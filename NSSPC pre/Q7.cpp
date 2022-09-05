#include <iostream>
#include <cmath>

struct Triangle
{
    int area;
    std::string type;
};

Triangle findTriangle(double a, double b, double c)
{
    Triangle result;

    // Find the area of the triange using Heron's formula
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        result.type = "Invalid";
        result.area = 0;
        return result;
    }
    else if (a == b && b == c)
    {
        result.type = "Equilateral Triangle";
    }
    else if (a == b || b == c || a == c)
    {
        result.type = "Isosceles Triangle";
    }
    else
    {
        result.type = "Scalene Triangle";
    }

    result.area = std::round(area);
    return result;
}

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    Triangle result = findTriangle(a, b, c);
    std::cout << result.type << std::endl;
    if (result.area)
        std::cout << result.area << std::endl;
}