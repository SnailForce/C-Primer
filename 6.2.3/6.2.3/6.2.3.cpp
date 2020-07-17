// 6.2.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
auto test(int n)
{
	return n * n;
}
auto findChar(const string& s, char c, decltype(s.size()) &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret)i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			
			if (ret == s.size())
			{
				ret = i;
			}
			++occurs;
		}
	}
	cout << occurs << endl;
	return ret;
}
int main()
{
	string s = "thhllhhop";
	char c = 'h';
	decltype(s.size()) occurs = 10;
	auto t = findChar(s, c, occurs);
	cout << t << " " << occurs << endl;
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
