#include <iostream>
using namespace std;
int main()
{
	int ia[3][4];
	int cnt = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ia[i][j] = cnt++;
		}
	}
	for (int(&r)[4] : ia)
	{
		for (int t : r)
		{
			cout << t << " ";
		}
		cout << endl;
	}
	cout << string(20, '=') << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << string(20, '=') << endl;
	for (int(*p)[4] = ia; p != ia + 3; ++p)
	{
		for (int* t = *p; t != *p + 4; ++t)
		{
			cout << *t << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}