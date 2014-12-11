#include "mystring.h"
#include <iostream>
using namespace MyString;
int main()
{
  mystring str;
  mystring str2;
  std::cout << "First string pls:\n";
  std::cin >> str;
  std::cout << "First string is: " << str << "\n";
  std::cout << "Second string pls:\n";
  std::cin >> str2;
  std::cout << "Second string is: " << str2 << "\n";
  mystring str3 = str + str2;
  std::cout << "Catenated string is:\n";
  std::cout << str3 << " " << str3.getLength()  << "\n";
  return 0;
}
