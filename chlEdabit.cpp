#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>

using namespace std;

void printIntVector(vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

void printStringVector(vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

bool isNumberPalindrome(int num)
{
    string str = to_string(num);
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

auto longBurp = [](int num)
{ return "Bu" + string(num, 'r') + "p"; };

vector<int> amplify(int n)
{
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
        {
            result.push_back(i * 10);
        }
        else
        {
            result.push_back(i);
        }
    }
    return result;
}

int getAbsSum(vector<int> arr)
{
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        result += abs(arr[i]);
    }
    return result;
}

string reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

vector<string> sortByLength(vector<string> arr)
{
    sort(arr.begin(), arr.end(), [](string a, string b)
         { return a.size() < b.size(); });
    return arr;
}

vector<int> arrayOfMultiples(int num, int length)
{
    vector<int> result;
    for (int i = 1; i <= length; i++)
    {
        result.push_back(i * num);
    }
    return result;
}

vector<string> firstAndLast(string word)
{
    sort(word.begin(), word.end());
    string revesed_word = word;
    reverse(revesed_word.begin(), revesed_word.end());
    return {word, revesed_word};
}

vector<int> leader(vector<int> arr)
{
    vector<int> ans;
    bool valid = true;

    for (int i = 0; i < arr.size(); i++)
    {
        valid = true;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] >= arr[i])
            {
                valid = false;
                break;
            }
        }
        if (valid)
            ans.push_back(arr[i]);
    }
    return ans;
}

vector<vector<int>> allPairs(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        if (m.find(target - arr[i]) != m.end())
        {
            vector<int> a = {target - arr[i], arr[i]};
            sort(a.begin(), a.end());
            ans.push_back(a);
        }
        else
        {
            m[arr[i]] = target - arr[i];
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> slidingSum(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size() - n + 1; i++)
    {
        if (accumulate(arr.begin() + i, arr.begin() + i + n, 0) == k)
        {
            ans.push_back(vector<int>(arr.begin() + i, arr.begin() + i + n));
        }
    }

    return ans;
}

bool firstBeforeSecond(string str, char first, char second)
{
    return str.find_last_of(first) < str.find(second);
}

vector<int> digitalCipher(string message, int key)
{
    string key_char = to_string(key);
    vector<int> ans;
    for (int i = 0; i < message.size(); i++)
    {
        int c = message[i] - 'a';
        int k = key_char[i % key_char.size()] - '0';
        ans.push_back(c + k + 1);
    }
    return ans;
}

string getFirstItem(string arr[10])
{
    return arr[0];
}

bool isSafeBridge(string s)
{
    return s.find(" ") != string::npos;
}

string doubleSwap(string s, char c1, char c2)
{
    for (char &c : s)
    {
        if (c == c1)
            c = c2;
        else if (c == c2)
            c = c1;
    }
    return s;
}

string uncensor(string str, string vowels)
{
    for (int i = str.size(); i >= 0; i--)
    {
        if (str[i] == '*')
        {
            str[i] = vowels[vowels.size() - 1];
            vowels.pop_back();
        }
    }
    return str;
}

int letterCounter(vector<vector<char>> arr, char c)
{
    auto flattened = accumulate(
        arr.begin(),
        arr.end(),
        decltype(arr)::value_type{},
        [](auto x, auto y)
        {
            x.insert(x.end(), y.begin(), y.end());
            return x;
        });

    return count(flattened.begin(), flattened.end(), c);
}

int letterCounter2(vector<vector<char>> arr, char c)
{
    int count = 0;
    for (vector<char> i : arr)
    {
        for (char j : i)
        {
            if (j == c)
                count++;
        }
    }

    return count;
}

array<int, 2> sumOddAndEven(std::vector<int> arr)
{
    array<int, 2> sum = {0, 0};

    for (int i : arr)
    {
        sum[abs(i % 2)] += i;
    }

    return sum;
}

vector<vector<int>> squarePatch(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, n));
    return ans;
}

int main()
{
    // cout << isNumberPalindrome(1122332211) << endl;
    // cout << longBurp(13) << endl;
    // printStrVector(amplify(20));
    // cout << getAbsSum({-1, -3, -5, -4, -10, 0}) << endl;
    // cout << reverse("Hello World!") << endl;
    // printStringVector(sortByLength({"Leonardo", "Michelangelo", "Raphael", "Donatello"}));
    // printIntVector(arrayOfMultiples(7, 10));
    // printStringVector(firstAndLast("marmite"));
    // printIntVector(leader({8, 7, 1, 2, 10, 3, 5}));
    // vector<vector<int>> ans = allPairs({4, 5, 1, 3, 6, 8}, 9);
    // for (int i = 0; i < ans.size(); i++) {
    //     printIntVector(ans[i]);
    // }
    // vector<vector<int>> ans = slidingSum({1, 4, 2, 3, 5, 0}, 2, 5);
    // for (int i = 0; i < ans.size(); i++) {
    //     printIntVector(ans[i]);
    // }
    // cout << firstBeforeSecond("a rabbit jumps joyfully", 'a', 'j') << endl;
    // printIntVector(digitalCipher("pakistanairforce", 1965));
    // printStringVector(bestWords({"berry","whiz","laughed","ghetto","psychic"}));

    // cout << isSafeBridge("####") << endl;
    // cout << doubleSwap("**##**", '*', '#') << endl;
    // cout << uncensor("Wh*r* d*d my v*w*ls g*?", "eeioeo") << endl;

    // vector<vector<char>> nestedArr = {
    //     {'D', 'E', 'Y', 'H', 'A', 'D'},
    //     {'C', 'B', 'Z', 'Y', 'J', 'K'},
    //     {'D', 'B', 'C', 'A', 'M', 'N'},
    //     {'F', 'G', 'G', 'R', 'S', 'R'},
    //     {'V', 'X', 'H', 'A', 'S', 'S'}};

    // cout << letterCounter2(nestedArr, 'D') << endl;

    vector<vector<int>> sus = squarePatch(5);

    for (int i = 0; i < 5; i++)
    {
        cout << "[";
        for (int j = 0; j < 5; j++)
        {
            cout << sus[i][j] << (j < 4 ? ", " : "");
        }
        cout << "]" << endl;
    }
}
