#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <stdexcept>
namespace MyString
{
  class mystring 
  {
  private:
    char *str;
    int length;
  public:
    // Constructors
    mystring();
    mystring(char *str);
    mystring& operator=(char *s);
    mystring& operator=(const mystring &other);
  
    // Getter methods
    int getLength() const;
    char * getStr();

    // Operator overloads
    char operator[](int index);
    mystring operator+(const mystring& start);
    mystring operator+(char *s);
  
    // Other funny methods
    mystring subString(int index);
    mystring erase(char c);
    void swap(mystring& other);
    void replace(int index, char c);
    void push_back(char c);

    // Input and output overloads
    friend std::ostream& operator<<(std::ostream& output, const mystring &s)
    {
      output << s.str;
      return output;
    }
    friend std::istream& operator>>(std::istream& input, mystring &s)
    {
      
    }
  
    // Destructor
    ~mystring();
  };
}
#endif
