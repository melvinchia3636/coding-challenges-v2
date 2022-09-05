#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <string.h>

struct IntersectionPoint
{
    std::string x;
    std::string y;
};

struct Intersection
{
    std::string stats;
    IntersectionPoint point[2];
};

std::string getDoubleWithcision(double value, int precision)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}

Intersection findIntersection(double m, double c)
{
    // calculate the difference between two lines
    double A = 1;
    double B = -2 - m;
    double C = -3 - c;

    // calculate the discriminant
    double d = B * B - 4 * A * C;

    Intersection result;

    if (d < 0)
    {
        // no solution if d < 0
        result.stats = "No intersection";
    }
    else if (d == 0)
    {
        // one solution if d == 0, and calculate the x and y coordinate
        result.stats = "One intersection";
        double x1 = -B / (2 * A);
        double y1 = m * x1 + c;

        result.point[0].x = getDoubleWithcision(x1, 7);
        result.point[0].y = getDoubleWithcision(y1, 7);
        result.point[1].x = "";
        result.point[1].y = "";
    }
    else
    {
        // two solutions if d > 0, and calculate their x and y coordinate
        result.stats = "Two intersections";
        double x1 = (-B + sqrt(d)) / (2 * A);
        double y1 = m * x1 + c;
        double x2 = (-B - sqrt(d)) / (2 * A);
        double y2 = m * x2 + c;

        result.point[0].x = getDoubleWithcision(x1, 7);
        result.point[0].y = getDoubleWithcision(y1, 7);
        result.point[1].x = getDoubleWithcision(x2, 7);
        result.point[1].y = getDoubleWithcision(y2, 7);
    }

    return result;
}

int main()
{
    double m, c;
    std::cin >> m >> c;

    Intersection result = findIntersection(m, c);
    std::cout << result.stats << std::endl;

    for (int i = 0; i < 2; i++)
    {
        if (result.point[i].x.size())
            std::cout << result.point[i].x << ", " << result.point[i].y << std::endl;
    }
}