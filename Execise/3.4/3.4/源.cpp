#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)
	{
		cout << "ПаµИ" << endl;
	}
	else if (s1 > s2)
	{
		cout << s1 << endl;
	}
	else
	{
		cout << s2 << endl;
	}
	auto t1 = s1.size();
	auto t2 = s2.size();
	system("pause");
	return 0;
}