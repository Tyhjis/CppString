#include "mystring.h"
#include <iostream>

int main()
{
  std::string s;
  mystring str1 = "Hi";
  mystring str2 = "World";
  mystring str3 = str1 + "World";
  std::cout << "str1: " << str1 << " " << str1.getLength() << "\n";
  std::cout << "str2: " << str2 << " " << str2.getLength() << "\n";
  char c = 'c';
  try {
    c = str3[9];
  } catch(const std::out_of_range& oor) {
    std::cerr << "Out of range error: " << oor.what() << "\n";
  }
  std::cout << c << "\n";
  str1.swap(str2);
  std::cout << "str1: " << str1 << " " << str1.getLength() << "\n"; 
  std::cout << "str2: " << str2 << " " << str2.getLength() << "\n";
  str1.replace(0, 'B');
  std::cout << "str1: " << str1 << " " << str1.getLength() << "\n";
  return 0;
}
