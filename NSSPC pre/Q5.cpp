#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

const int PRIME[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

std::string primeSumOfStringChar(std::string str)
{
    // check if the string length is bigger than 100
    if (str.size() > 100)
    {
        return "Invalid Length";
    }

    // turn the string into all lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    // remove all non-alphabet characters
    str.erase(std::remove_if(str.begin(), str.end(), [](char c)
                             { return !(c >= 'a' && c <= 'z'); }),
              str.end());

    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        // check if the index of character is prime number
        int index = str[i] - 'a' + 1;
        if (std::find(PRIME, PRIME + 9, index) != PRIME + 9)
        {
            count += index;
        }
    }

    return std::to_string(count);
}

int main()
{
    assert(primeSumOfStringChar("Hello World") == "28");
    assert(primeSumOfStringChar("Thanks for participating in NSS COMPETITION 2022!") == "99");
    assert(primeSumOfStringChar("“NTU is the most prestigious comprehensive university in Taiwan and one of the top-ranked universities in Asia.”") == "Invalid Length");
    assert(primeSumOfStringChar("National Zoo") == "0");
    assert(primeSumOfStringChar("@ABCDefgHIjklMNopQRstUVWXYZ@") == "100");

    std::string str;
    std::getline(std::cin >> std::ws, str);

    std::cout << primeSumOfStringChar(str) << std::endl;
}