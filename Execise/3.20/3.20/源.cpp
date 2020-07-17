#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> t;
	decltype(t.size()) r;
	while (cin >> r)
	{
		t.push_back(r);
	}
	for (decltype(t.size())index = 0; index < t.size() - 1; ++index)
	{
		cout << t.at(index) + t.at(index + 1) << " ";
	}
	cout << endl;
	cin.clear();
	cin.ignore();
	system("pause");
	return 0;
}