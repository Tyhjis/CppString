#include "mystring.h"
#include <iostream>

int mystring::getLength()
{
  return length;
}

mystring::mystring()
{
  this->str = 0;
  this->length = 0;
}

mystring::mystring(char *str)
{
  this->str = str;
  int i = 0;
  while(str[i] != '\0') {
    i++;
  }
  this->length = i;
}

mystring& mystring::operator=(char *s)
{
  this->str = s;
  int i = 0;
  while(s[i] != '\0'){
    i++;
  }
  this->length = i;
}

mystring& mystring::operator=(const mystring &other)
{
  this->str = other.str;
  int i = 0;
  while(other.str[i] != '\0'){
    i++;
  }
  this->length = i;
}

mystring mystring::operator+(const mystring& start)
{
  char * destination = this->str;
  int i = getLength();
  int j = 0;
  char * startstring = start.str;
  while(startstring[j] != '\0'){
    j++;
  }
  char * newstr = new char[i+j+1];
  i = 0;
  j = 0;
  while(destination[i] != '\0') {
    newstr[i] = destination[i];
    i++;
  }
  while(startstring[j] != '\0') {
    newstr[i+j] = startstring[j];
    j++;
  }
  newstr[i+j] = '\0';
  mystring ret(newstr);
  return ret;
}

mystring mystring::operator+(char *s)
{
  char * destination = this->str;
  int i = getLength();
  int j = 0;
  char * startstring = s;
  while(startstring[j] != '\0'){
    j++;
  }
  char * newstr = new char[i+j+1];
  i = 0;
  j = 0;
  while(destination[i] != '\0'){
    newstr[i] = destination[i];
    i++;
  }
  while(startstring[j] != '\0'){
    newstr[i+j] = startstring[j];
    j++;
  }
  newstr[i+j] = '\0';
  mystring ret(newstr);
  return ret;
}

char mystring::operator[](int index)
{
  if(index < 0 || index >= length){
    throw std::out_of_range("Index out of bounds");
  }
  return this->str[index];
}

mystring mystring::subString(int index)
{
  
}

char * mystring::getStr()
{
  return this->str;
}

mystring::~mystring()
{
}
