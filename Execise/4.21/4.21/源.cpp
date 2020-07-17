#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
int main()
{
	srand((unsigned) time(NULL));
	vector<int> t;
	for (auto i = 0; i < 10; ++i)
	{
		t.push_back(rand() % 100);
	}
	for (auto c : t)
	{
		cout << c << " ";
	}
	cout << endl;
	for (auto& c : t)
	{
		c = c % 2 ? c * 2 : c;
		cout << c << " ";
	}
	cout << endl;
	int grade;
	while (cin >> grade)
	{
		string finalgrade = grade > 90 ? "high pass" : grade > 75 ? "pass" : grade > 60 ? "low pass" : "fail";
		cout << finalgrade << endl;
	}
	cin.clear();
	cin.sync();
	system("pause");
	return 0;
}