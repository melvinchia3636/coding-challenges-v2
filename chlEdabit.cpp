#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>

void printIntVector(std::vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
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

std::vector<int> leader(std::vector<int> arr) {
	std::vector<int> ans;
    bool valid = true;
    
    for (int i = 0; i < arr.size(); i++) {
        valid = true;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] >= arr[i]) {
                valid = false;
                break;
            }
        }
        if (valid) ans.push_back(arr[i]);
    }
    return ans;
}

std::vector<std::vector<int>> allPairs(std::vector<int> arr, int target) {
    std::vector<std::vector<int>> ans;
	std::map<int, int> m;

    for (int i = 0; i < arr.size(); i++) {
        if (m.find(target-arr[i]) != m.end()) {
            std::vector<int> a = {target-arr[i], arr[i]};
            std::sort(a.begin(), a.end());
            ans.push_back(a);
        } else {
            m[arr[i]] = target-arr[i];
        }
    }

    std::sort(ans.begin(), ans.end());
    return ans;
}

std::vector<std::vector<int>> slidingSum(std::vector<int> arr, int n, int k) {
    std::vector<std::vector<int>> ans;

	for (int i = 0; i < arr.size() - n + 1; i++) {
        if (std::accumulate(arr.begin() + i, arr.begin() + i + n, 0) == k) {
            ans.push_back(std::vector<int>(arr.begin() + i, arr.begin() + i + n));
        }
    }

    return ans;
}

int main() {
    // cout << isNumberPalindrome(1122332211) << endl;
    // std::cout << longBurp(13) << std::endl;
    // printStrVector(amplify(20));
    // std::cout << getAbsSum({-1, -3, -5, -4, -10, 0}) << std::endl;
    // std::cout << reverse("Hello World!") << std::endl;
    // printStringVector(sortByLength({"Leonardo", "Michelangelo", "Raphael", "Donatello"}));
    // printIntVector(arrayOfMultiples(7, 10));
    // printStringVector(firstAndLast("marmite"));
    // printIntVector(leader({8, 7, 1, 2, 10, 3, 5}));
    // std::vector<std::vector<int>> ans = allPairs({4, 5, 1, 3, 6, 8}, 9);
    // for (int i = 0; i < ans.size(); i++) {
    //     printIntVector(ans[i]);
    // }

    std::vector<std::vector<int>> ans = slidingSum({1, 4, 2, 3, 5, 0}, 2, 5);
    for (int i = 0; i < ans.size(); i++) {
        printIntVector(ans[i]);
    }
}