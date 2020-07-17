#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<string> t{ "cppprimer", "javacore", "pythoncookbook", "cc" };
	auto r = partition(t.begin(), t.end(), [](const string& s) -> bool {return s.size() >= 5; });
	for (auto t1 = t.begin(); t1 < r; t1++)
	{
		cout << *t1 << " ";
	}
	cout << endl;
	return 0;
}