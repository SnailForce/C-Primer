#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
	const int size = 10;
	srand((unsigned)time(NULL));
	int t[size];
	for (int i = 0; i < 10; ++i)
	{
		t[i] = rand() % 100;
	}
	for (auto c : t)
	{
		cout << c << " ";
	}
	cout << endl;
	vector<int> vInt(begin(t) + 1, end(t) - 1);
	for (auto c : vInt)
	{
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}