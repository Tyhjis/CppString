#include "testclass.h"
#include "mystring.h"

void testclass::testconstructor()
{
	std::cout << "Testing = constructor.\n";
	MyString::mystring m = "Moi";
	assert(m.getLength() == 3);
	char * c = m.getStr();
	assert(c[0] == 'M');
	assert(c[1] == 'o');
	assert(c[2] == 'i');
	std::cout << "constructor = works!\n";
}

void testclass::testconstructor2()
{
	std::cout << "Testing constructor that takes char pointer as argument.\n";
	char *s = "Moi";
	MyString::mystring m1(s);
	char *s2 = m1.getStr();
	int i;
	for(i = 0; s2[i] != '\0'; i++)
	{
		assert(s2[i] == s[i]);
	}
	std::cout << "Constructor with char pointer works!\n";
}

void testclass::testconstructor3()
{
	std::cout << "Testing constructor which takes another mystring object as argument.\n";
	MyString::mystring m2 = "Moi";
	MyString::mystring m1 = m2;
	assert(m1.getLength() == 3);
	assert(m1[0] == 'M');
	assert(m1[1] == 'o');
	assert(m1[2] == 'i');
	std::cout << "Constructor with another mystring works!\n";
}

void testclass::testcatenate()
{
	std::cout << "Catenating another mystring to another mystring (operator +).\n";
	MyString::mystring m = "Moi";
	MyString::mystring s = "Hei";
	m = m + s;
	assert(m.getLength() == 6);
	char * c = m.getStr();
	assert(c[0] == 'M');
	assert(c[1] == 'o');
	assert(c[2] == 'i');
	assert(c[3] == 'H');
	assert(c[4] == 'e');
	assert(c[5] == 'i');
	std::cout << "Catenating works!\n";
}

void testclass::testcatenate2()
{
	std::cout << "Catenating a string literal to the end of mystring (operator +).\n";
	MyString::mystring m = "Hello";
	MyString::mystring m2 = m + "World";
	assert(m2.getLength() == 10);
	char *s = m2.getStr();
	char *s2 = "HelloWorld";
	int i;
	for(i = 0; s[i] != '\0'; i++)
	{
		assert(s[i] == s2[i]);
	}
	std::cout << "Catenating with literal works!\n";
}

void testclass::testlength()
{
	std::cout << "Testing if getLength method return correct length. Using string Kristian. Should return 8.\n";
	MyString::mystring m = "Kristian";
	assert(m.getLength() == 8);
	std::cout << "Length function works!\n";
}

void testclass::testsubstr()
{
	std::cout << "Testing subString formation. SubString should return another mystring which is a substring of the invoked mystring. Takes index as argument.\n";
	MyString::mystring first = "Hello";
	MyString::mystring sec = first.subString(2);
	assert(sec.getLength() == 3);
	char * str = sec.getStr();
	assert(str[0] == 'l');
	assert(str[1] == 'l');
	assert(str[2] == 'o');
	std::cout << "Substring works!\n";
}

void testclass::testaccessoperator()
{
	std::cout << "Testing access operator []. The operator should return the correct character. String used here is Moi. All the characters are accessed.\n";
	MyString::mystring m = "Moi";
	assert(m[0] == 'M');
	assert(m[1] == 'o');
	assert(m[2] == 'i');
	std::cout << "Accessing works!\n";
}

void testclass::testswap()
{
	std::cout << "Testing string swap. Swap takes another mystring as argument.\n";
	MyString::mystring m1 = "Yolo";
	MyString::mystring m2 = "Hipster";
	assert(m1.getLength() == 4);
	assert(m2.getLength() == 7);
	m1.swap(m2);
	assert(m1.getLength() == 7);
	assert(m2.getLength() == 4);
	std::cout << "Swapping works!\n";
}

void testclass::testerase()
{
	std::cout << "Testing erasing. Erase takes a character as argument. Returns another mystring.\n";
	MyString::mystring m = "Hello";
	MyString::mystring m2 = m.erase('l');
	MyString::mystring m3 = m.erase('c');
	assert(m.getLength() == 5);
	assert(m2.getLength() == 3);
	assert(m3.getLength() == 5);
	assert(m2[0] == 'H');
	assert(m2[1] == 'e');
	assert(m2[2] == 'o');
	assert(m3[0] == 'H');
	assert(m3[1] == 'e');
	assert(m3[2] == 'l');
	assert(m3[3] == 'l');
	assert(m3[4] == 'o');
	std::cout << "Erasing works!\n";
}

void testclass::testreplace()
{
	std::cout << "Testing replacing. Replace takes index and a character as arguments. Return new mystring object which has the character replaced.\n";
	MyString::mystring m = "Moi";
	MyString::mystring m2 = m.replace(1, 'a');
	assert(m2[0] == 'M');
	assert(m2[1] == 'a');
	assert(m2[2] == 'i');
	std::cout << "Replacing works!\n";
}

void testclass::testpushback()
{
	std::cout << "Testing push_back. Push_back takes a character as argument which is then pushed at the end of the string.\n";
	MyString::mystring m = "Moi";
	char c = 'c';
	m.push_back(c);
	assert(m.getLength() == 4);
	assert(m[3] == 'c');
	std::cout << "Pushing back works!\n";
}

void testclass::testcompare()
{
	std::cout << "Testing compare (operator ==). Should return true if mystrings are the same. False if not.\n";
	MyString::mystring m1 = "Moi";
	MyString::mystring m2 = "Moi";
	MyString::mystring m3 = "Hei";
	assert((m1 == m2) == true);
	assert((m2 == m3) == false);
	std::cout << "Comparing works!\n";
}

void testclass::testcompare2()
{
	std::cout << "Testing compare (operator ==). This time comparing with a string literal.\n";
	MyString::mystring m1 = "Moi";
	assert((m1 == "Moi") == true);
	assert((m1 == "Hei") == false);
	std::cout << "Comparing with literal works!\n";
}
