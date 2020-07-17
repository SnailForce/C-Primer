#include <iostream>
using namespace std;
int main()
{
	size_t cnt = 0;
	int ia[3][4];
	for (auto& row : ia)
	{
		for (auto& col : row)
		{
			col = 2 * (cnt++);
		}
	}
	for (auto& c : ia)
	{
		for (auto t : c)
		{
			cout << t << endl;
		}
	}
	int(*p)[4] = ia;
	for (auto& c : *p)
	{
		cout << c << " ";
	}
	p = &ia[2];
	for (auto& c : *p)
	{
		cout << c << " ";
	}
	cout << endl << string(30, '=') << endl;
	for (auto p = ia; p != ia + 3; ++p)
	{
		cout << p << " "
			" " << *p << endl;
		for (auto q = *p; q != *p + 4; ++q)
		{
			cout << *q << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << string(30, '=') << endl;
	for (auto p = begin(ia); p != end(ia); ++p)
	{
		for (auto q = begin(*p); q != end(*p); ++q)
		{
			cout << *q << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}