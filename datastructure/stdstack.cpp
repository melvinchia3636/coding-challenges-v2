#include <iostream>
#include <cstdio>
#include <stack>

// Last in First out

int main() {
  std::stack<int> myStack;
  
  myStack.push(5);
  myStack.push(4);
  myStack.push(3);
  myStack.push(2);
  myStack.push(1);

  std::printf("the stack size is: %d\n", myStack.size());
  if (!myStack.empty()) 
    std::printf("the top element is: %d\n", myStack.top());
  
  myStack.pop();
  std::printf("now the stack size is: %d\n", myStack.size());
  if (!myStack.empty()) 
    std::printf("now the top element is: %d\n", myStack.top());
  

  return 0;
}