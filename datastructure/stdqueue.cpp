#include <iostream>
#include <queue>

// First in First out

int main() {
  std::queue<int> myQueue;
  
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  myQueue.push(4);
  myQueue.push(5);

  std::cout << "the queue size is: " << myQueue.size() << std::endl;
  if (!myQueue.empty()) {
    std::cout << "the front element is: " << myQueue.front() << std::endl;
  }
  myQueue.pop();
  std::cout << "now the queue size is: " << myQueue.size() << std::endl;
  if (!myQueue.empty()) {
    std::cout << "now the front element is: " << myQueue.front() << std::endl;
  }

  return 0;
}