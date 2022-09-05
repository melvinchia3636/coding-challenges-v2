#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

// calculate the convert ratio given by the question
const double convertRatio = 2800 / (99 + 273.15);

std::string VolOfBalloon(double temp)
{
    // convert the temp to farhenheit and calculate the volume of the balloon
    double volume = (temp + 273.15) * convertRatio;

    // convert the volume to string with 7 decimal places
    std::stringstream volumeStr;
    volumeStr << std::fixed << std::setprecision(7) << volume;
    std::string result = volumeStr.str();

    return result;
}

int main()
{
    // I'm too lazy to write the assertions

    int t;
    std::cin >> t;
    std::string temps[t];

    for (int i = 0; i < t; i++)
    {
        double temp;
        std::cin >> temp;
        temps[i] = VolOfBalloon(temp);
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << temps[i] << std::endl;
    }
}