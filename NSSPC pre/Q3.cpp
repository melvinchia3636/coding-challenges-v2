#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <assert.h>

std::string tempConvert(std::string temp)
{
    // split the temp string into temp value and temp type
    char type = temp[temp.length() - 1];
    std::string val = temp.substr(0, temp.length() - 1);
    float value = std::stof(val);

    float targetValue = 0;

    // convert the temp value from C to F or vice versa
    switch (type)
    {
    case 'C':
        targetValue = value * 9 / 5 + 32;
        break;
    case 'F':
        targetValue = (value - 32) * 5 / 9;
        break;
    }

    // convert the target value to string with 1 decimal places
    std::stringstream targetValueStr;
    targetValueStr << std::fixed << std::setprecision(1) << targetValue;

    // join the target value and target type
    std::string result = targetValueStr.str() + (type == 'C' ? "F" : "C");

    return result;
}

int main()
{
    assert(tempConvert("90F") == "32.2C");
    assert(tempConvert("35C") == "95.0F");
    assert(tempConvert("-0.5F") == "-18.1C");
    assert(tempConvert("-30.8C") == "-23.4F");
    assert(tempConvert("-55.3F") == "-48.5C");
    assert(tempConvert("26.3C") == "79.3F");
    assert(tempConvert("32F") == "0.0C");

    std::string temp;
    std::cin >> temp;

    std::cout << tempConvert(temp) << std::endl;
}