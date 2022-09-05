#include <iostream>
#include <string>
#include <iomanip>
#include <assert.h>
#include <string.h>

struct BMI
{
    std::string bmi;
    std::string category;
};

bool operator==(const BMI &lhs, const BMI &rhs)
{
    return lhs.bmi == rhs.bmi && lhs.category == rhs.category;
}

BMI calculateBMI(float kg, float m)
{
    // calculate the bmi value
    float bmi = kg / (m * m);
    std::string category;

    // check the bmi value and assign the category
    if (bmi < 18.5)
    {
        category = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        category = "Healthy Weight";
    }
    else if (bmi >= 25 && bmi < 30)
    {
        category = "Overweight";
    }
    else
    {
        category = "Obesity";
    }

    // convert the bmi value to string with 2 decimal places
    std::stringstream bmistr;
    bmistr << std::fixed << std::setprecision(2) << bmi;

    // return the bmi value and category
    BMI result;
    result.bmi = bmistr.str();
    result.category = category;
    return result;
}

int main()
{
    BMI test1 = {bmi : "12.35", category : "Underweight"};
    BMI test2 = {bmi : "34.60", category : "Obesity"};
    BMI test3 = {bmi : "24.69", category : "Healthy Weight"};
    BMI test4 = {bmi : "27.50", category : "Overweight"};
    BMI test5 = {bmi : "20.76", category : "Healthy Weight"};

    assert(calculateBMI(40, 1.8) == test1);
    assert(calculateBMI(100, 1.7) == test2);
    assert(calculateBMI(80, 1.8) == test3);
    assert(calculateBMI(110, 2) == test4);
    assert(calculateBMI(60, 1.7) == test5);

    float kg, m;
    std::cin >> kg >> m;
    BMI result = calculateBMI(kg, m);
    std::cout << result.bmi << "\n"
              << result.category << std::endl;
}