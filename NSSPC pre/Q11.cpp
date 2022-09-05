#include <iostream>
#include <string>
#include <assert.h>

std::string OTP(std::string n)
{
    char raw[4];

    raw[0] = n[1];
    raw[1] = n[3];
    raw[2] = n[2];
    raw[3] = n[0];

    int otpSeed = std::stoi(raw);

    long otpSquare = otpSeed * otpSeed;
    std::string otpSquareStr = std::to_string(otpSquare);

    long otp = std::stol(otpSquareStr.substr(otpSquareStr.size() - 6, 6));
    long otpSquare2 = otp * otp;
    std::string otp2 = std::to_string(otpSquare2);
    std::string otpFinal = otp2.substr(otp2.size() - 6, 6);

    return otpFinal;
}

int main()
{
    assert(OTP("5678") == "640625");
    assert(OTP("9999") == "960001");
    assert(OTP("5532") == "300625");
    assert(OTP("1234") == "077121");
    assert(OTP("3025") == "113841");
    assert(OTP("7928") == "065041");

    char n[4];
    std::cin >> n;
    std::cout << OTP(n) << std::endl;
}