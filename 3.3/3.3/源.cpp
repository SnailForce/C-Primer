#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string ss(10, 'h');
	cout << ss << endl;
	vector<string> v{ "a","an","the" };
	vector<int> v1(10, -1);
	vector<int> tt;
	cout << tt.size() << endl;  // 0
	vector<int> t{ 0,1,2,3,4,5,6,7,8,9 };
	for (auto& c : t)
	{
		c *= c;
	}
	for (auto& c : t)
	{
		cout << c << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}