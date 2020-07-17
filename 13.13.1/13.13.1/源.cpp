#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t = 10;
	vector<int> s;
	s.push_back(t);
	t = 20;
	for (auto i : s)
	{
		cout << i << endl;
	}
	return 0;
}