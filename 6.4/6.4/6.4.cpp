// 6.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const string& shorterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
string& shorterString(string& s1, string& s2)
{
	auto& r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	cout << typeid(r).name();
	return const_cast<string&>(r);
}
int main()
{
	string s1 = "222";
	string s2 = "33333";
	cout << shorterString(s1, s2);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
