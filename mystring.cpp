#include "mystring.h"
#include <iostream>
namespace MyString
{
  int mystring::getLength() const
  {
	int i;
	for(i = 0; this->str[i] != '\0'; i++);
    return i;
  }

  mystring::mystring()
  {
    this->str = new char[1];
    this->str[0] = '\0';
  }

  mystring::mystring(char *str)
  {
    this->str = str;
  }

  mystring& mystring::operator=(char *s)
  {
	int i = 0;
    while(s[i] != '\0') {
		i++;
    }
    i++;
    this->str = new char[i];
    i = 0;
    while(s[i] != '\0') {
		this->str[i] = s[i];
		i++;
	}
	this->str[i] = '\0';
  }

  mystring& mystring::operator=(const mystring &other)
  {
    int i = 0;
    while(other.str[i] != '\0') {
		i++;
	}
	i++;
	this->str = new char[i];
	i = 0;
	while(other.str[i] != '\0') {
		this->str[i] = other.str[i];
		i++;
	}
	this->str[i] = '\0';
  }

  mystring mystring::operator+(const mystring& start)
  {
    char * destination = this->str;
    int i = getLength();
    int j = start.getLength();
    char * startstring = start.str;
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
  
  bool mystring::operator==(const mystring& other)
  {
	  int i;
	  if(getLength() != other.getLength())
	  {
		  return false;
	  }
	  for(i = 0; this->str[i] != '\0'; i++)
	  {
		  if(this->str[i] != other.str[i])
		  {
			  return false;
		  }
	  }
	  return true;
  }
  
  bool mystring::operator==(const char *s)
  {
	  int i;
	  for(i = 0; s[i] != '\0'; i++);
	  if(i != getLength())
	  {
		  return false;
	  }
	  i = 0;
	  for(i = 0; this->str[i] != '\0'; i++)
	  {
		  if(this->str[i] != s[i])
		  {
			  return false;
		  }
	  }
	  return true;
	}
  char mystring::operator[](int index)
  {
    if(index < 0 || index >= getLength()){
      throw std::out_of_range("Index out of bounds.");
    }
    return this->str[index];
  }

  mystring mystring::subString(int index)
  {
	  int l = getLength();
    if(index < 0 || index >= l){
      throw std::out_of_range("Index out of bounds.");
    }
    int newlength = l - index;
    char *substr = new char[newlength];
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
  }

  mystring mystring::replace(int index, char c) {
	  int l = getLength();
	  if(index < 0 || index >= l){
		  throw std::out_of_range("Index out of bounds.");
	  }
	  char *s = new char[l];
	  int i = 0;
	  while(this->str[i] != '\0') {
		if(i == index) {
			s[i] = c;
		} else {
			s[i] = this->str[i];
		}
		i++;
	  }
	  mystring ret(s);
	  return s;
  }

  char * mystring::getStr()
  {
    return this->str;
  }
  
  void mystring::push_back(char c)
  {
	  int l = getLength();
	  char * s = new char[l+1];
	  int i = 0;
	  while(this->str[i] != '\0')
	  {
		  s[i] = this->str[i];
		  i++;
	  }
	  s[i] = c;
	  s[i+1] = '\0';
	  this->str = s;
  }  
  mystring::~mystring(){ }
}
