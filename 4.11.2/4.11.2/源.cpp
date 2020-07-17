#include <iostream>
using namespace std;
int main()
{
	int ia[]{ 0,1,2,3,4,5,6,7,8,9 };
	decltype(ia) ib{ 1,2,3 };
	for (auto c : ib)
	{
		cout << c << " ";
	}
	system("pause");
	return 0;
}