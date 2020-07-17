#include <bits/stdc++.h>
using namespace std;
int main()
{
	auto c1 = "hello";
	auto c2 = "world";
	unsigned l = strlen(c1) + strlen(c2) + 1;
	cout << strlen(c1) << " " << strlen(c2) << "\n";
	char* r = new char[l]();
	cout << r << ": " << strlen(r) << "\n";
	strcat_s(r, l, c1);
	strcat_s(r, l, c2);
	cout << r << "\n";

	string s1 = "hello";
	string s2 = "world";
	strcpy_s(r, l, (s1 + s2).c_str());
	cout << r << "\n";
	return 0;
}
