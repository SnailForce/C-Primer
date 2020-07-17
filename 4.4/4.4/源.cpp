#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> t{ 1,2,3,4,5 };
	for (auto beg = t.begin(); beg != t.end(); ++beg)
	{
		cout << *beg << " ";
	}
	system("pause");
	return 0;
}