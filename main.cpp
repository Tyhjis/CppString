#include "mystring.h"
#include <iostream>
#include <assert.h>
#include "testclass.h"
using namespace MyString;
int main()
{
	std::cout << "This is the program for testing my own string class.\n";
	testclass test;
	test.testconstructor();
	test.testconstructor2();
	test.testconstructor3();
	test.testcatenate();
	test.testcatenate2();
	test.testlength();
	test.testsubstr();
	test.testaccessoperator();
	test.testswap();
	test.testerase();
	test.testreplace();
	test.testpushback();
	test.testcompare();
	test.testcompare2();
	mystring str;
	std::cout << "Now let's test input by manually:\nPlease give a string:\n";
	std::cin >> str;
	std::cout << "Here is the string you gave: " << str << "\nI hope it's correct.\nProgram ends.\n";
    return 0;
}
