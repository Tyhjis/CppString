#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <stdexcept>
class mystring 
{
 private:
  char *str;
  int length;
 public:
  mystring();
  mystring(char *str);
  int getLength();
  char * getStr();
  mystring& operator=(char *s);
  mystring& operator=(const mystring &other);
  char operator[](int index);
  mystring concat(mystring s);
  mystring operator+(const mystring& start);
  mystring operator+(char *s);
  mystring subString(int index);
  friend std::ostream& operator<<(std::ostream& output, const mystring &s)
  {
    output << s.str;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, mystring &s)
  {
    input >> s.str;
    return input;
  }
  ~mystring();
};

#endif
