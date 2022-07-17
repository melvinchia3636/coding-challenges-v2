#include <iostream>
#include <string>
#include <stack>
#include <cmath>

int main() {
  std::string s = "[()]{}{[()()]()}";

  std::stack<char> myStack;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      myStack.push(s[i]);
    } else {
      if (myStack.empty()) {
        std::cout << "false" << std::endl;
        return 0;
      }
      char c = myStack.top();
      if (!myStack.empty() || std::abs(c - s[i]) <= 2) {
        myStack.pop();
      } else {
        std::cout << "false" << std::endl;
        return 0;
      }
    }
  }
  if (myStack.empty()) std::cout << "true" << std::endl;
}