#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

void printIntVector(std::vector<int> const &input) {
    std::copy(
        input.begin(),
        input.end(),
        std::ostream_iterator<int>(std::cout, " ")
    );
    return;
}

void printStringVector(std::vector<std::string> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

bool isNumberPalindrome(int num) {
    std::string str = std::to_string(num);
    std::string reversed_str = str;
    std::reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

auto longBurp = [](int num) {return "Bu" + std::string(num, 'r') + "p";};

std::vector<int> amplify(int n) {
    std::vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            result.push_back(i * 10);
        } else {
            result.push_back(i);
        }
    }
    return result;
}

int getAbsSum(std::vector<int> arr) {
    int result = 0;
	for (int i = 0; i < arr.size(); i++) {
        result += std::abs(arr[i]);
    }
    return result;
}

std::string reverse(std::string str) {
    std::reverse(str.begin(), str.end());
	return str;
}

std::vector<std::string> sortByLength(std::vector<std::string> arr) {
	std::sort(arr.begin(), arr.end(), [](std::string a, std::string b) {return a.size() < b.size();});
    return arr;
}

std::vector<int> arrayOfMultiples(int num, int length) {
	std::vector<int> result;
    for (int i = 1; i <= length; i++) {
        result.push_back(i*num);
    }
    return result;
}

std::vector<std::string> firstAndLast(std::string word) {
    sort(word.begin(), word.end());
    std::string revesed_word = word;
    reverse(revesed_word.begin(), revesed_word.end());
    return { word, revesed_word };
}

int main() {
    // cout << isNumberPalindrome(1122332211) << endl;
    // std::cout << longBurp(13) << std::endl;
    // printStrVector(amplify(20));
    // std::cout << getAbsSum({-1, -3, -5, -4, -10, 0}) << std::endl;
    // std::cout << reverse("Hello World!") << std::endl;
    // printStringVector(sortByLength({"Leonardo", "Michelangelo", "Raphael", "Donatello"}));
    // printIntVector(arrayOfMultiples(7, 10));
    printStringVector(firstAndLast("marmite"));
}