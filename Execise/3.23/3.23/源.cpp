#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> t;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		t.push_back(rand() % 1000);
	}
	for (auto c : t)
	{
		cout << c << " ";
	}
	cout << endl;
	for (auto& c : t)
	{
		c *= 2;
		cout << c << " ";
	}
	cout << endl;
	for (auto it = t.begin(); it != t.end(); ++it)
	{
		cout << *it << " ";
		*it *= 2;
		cout << *it << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}