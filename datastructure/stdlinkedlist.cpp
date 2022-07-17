#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main() {
  std::list<std::string> membersOfMCCGA;
  std::list<std::string>::iterator it;

  membersOfMCCGA.push_back("Jiahuiiiii");
  membersOfMCCGA.push_back("Slimer");
  membersOfMCCGA.push_front("Melvin");

  std::list<std::string>::iterator whereIsMelvin = std::find(membersOfMCCGA.begin(), membersOfMCCGA.end(), "Melvin");
  std::cout << &whereIsMelvin << std::endl;

  it = membersOfMCCGA.begin();
  std::advance(it, 1);
  membersOfMCCGA.insert(it, "SUS");

  for (it = membersOfMCCGA.begin(); it != membersOfMCCGA.end(); ++it) {
    std::cout << *it << " yyds" << std::endl;
  }
  
  std::cout << "The size of the list is: " << membersOfMCCGA.size() << std::endl;

  it = membersOfMCCGA.begin();
  std::advance(it, 1);
  membersOfMCCGA.erase(it);
  // or membersOfMCCGA.remove("SUS");

  for (it = membersOfMCCGA.begin(); it != membersOfMCCGA.end(); ++it) {
    std::cout << *it << " yyds" << std::endl;
  }

  return 0;
}