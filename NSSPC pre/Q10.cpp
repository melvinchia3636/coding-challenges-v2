#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

std::string removeDup(std::string str)
{
    for (int i = 0; i < str.size() - 1; i++)
    {
        int j;
        // find the end index of ajacent duplicate characters
        for (j = i + 1; j < str.size(); j++)
        {
            if (str[i] != str[j])
            {
                break;
            }
        }

        // replace all the duplicate characters with "*"
        if (j - i > 1)
        {
            str.replace(i, j - i, 1, '*');
        }
    }

    // remove all the '*' characters
    str.erase(std::remove(str.begin(), str.end(), '*'), str.end());

    return str;
}

// check if the string has ajacent duplicate characters
bool isUnique(std::string str)
{
    if (str.size() == 0)
        return true;

    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }

    return true;
}

// remove duplicates until none are left
std::string untimateRemoveDup(std::string str)
{
    while (!isUnique(str))
    {
        str = removeDup(str);
    }

    return str.size() ? str : "Empty String";
}

int main()
{
    assert(untimateRemoveDup("bookkeeper") == "bper");
    assert(untimateRemoveDup("mississippi") == "m");
    assert(untimateRemoveDup("eezzzee") == "Empty String");
    assert(untimateRemoveDup("ratteennesss") == "rae");
    assert(untimateRemoveDup("sleeppooper") == "slper");
    assert(untimateRemoveDup("redivider") == "redivider");
    assert(untimateRemoveDup("tennet") == "Empty String");
    assert(untimateRemoveDup("tenet") == "tenet");

    std::string str;
    std::cin >> str;

    std::cout << untimateRemoveDup(str) << std::endl;
}