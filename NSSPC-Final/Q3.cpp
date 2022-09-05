#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

vector<string> split(string str)
{
    vector<string> result;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    result.push_back(temp);
    return result;
}

int main()
{
    string str;
    getline(cin >> ws, str);

    const string vowel = "AEIOU";

    str.erase(remove_if(str.begin(), str.end(), [](char c)
                        { return !isalpha(c) && c != ' '; }),
              str.end());

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    vector<string> v_str = split(str);

    int n = 0;

    for (string w : v_str)
    {
        int c = count_if(w.begin(), w.end(), [vowel](char c)
                         { return count(vowel.begin(), vowel.end(), c) > 0; });

        if (c > 2)
        {
            cout << w << endl;
            n++;
        }
    }

    cout << n << endl;
}