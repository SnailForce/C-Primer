#include <iostream>
using namespace std;
using intArray = int[4];
int main()
{
	int ia[3][4];
	int cnt = 0;
	for (auto& i : ia)
	{
		for (auto& j : i)
		{
			j = cnt++;
		}
	}
	for (intArray& t : ia)
	{
		for (int k : t)
		{
			cout << k << " ";
		}
		cout << endl;
	}
	for (intArray* t = ia; t != ia + 3; ++t)
	{
		for (int* p = *t; p != *t + 4; ++p)
		{
			cout << *p << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}