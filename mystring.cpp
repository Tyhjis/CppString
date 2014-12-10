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
    throw std::out_of_range("Index out of bounds.");
  }
  return this->str[index];
}

mystring mystring::subString(int index)
{
  if(index < 0 || index >= length){
    throw std::out_of_range("Index out of bounds.");
  }
  int newlength = length - index;
  char *substr = new char[newlength + 1];
  int i = index;
  int j = 0;
  while(this->str[i] != '\0'){
    substr[j] = this->str[i];
    i++;j++;
  }
  substr[j+1] = '\0';
  mystring ret(substr);
  return ret;
}

mystring mystring::erase(char c)
{
  char *s = new char;
  int i = 0;
  int j = 0;
  while(this->str[i] != '\0'){
    if(this->str[i] != c){
      s[j] = this->str[i];
      i++;j++;
    }
    else {
      i++;
    }
  }
  s[j+1] = '\0';
  mystring ret(s);
  return ret;
}

void mystring::swap(mystring& other)
{
  char * str = other.getStr();
  other.str = this->str;
  this->str = str;
  int l = other.getLength();
  other.length = length;
  length = l;
}

void mystring::replace(int index, char c) {
  if(index < 0 || index >= length){
    throw std::out_of_range("Index out of bounds");
  }
}

char * mystring::getStr()
{
  return this->str;
}

mystring::~mystring()
{
}
