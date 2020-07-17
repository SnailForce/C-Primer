#include <iostream>
using namespace std;
int main()
{
	int t = 10;
	bool b = true;
	cout << t + b << endl;  // 11
	b = -b;
	cout << t + b << endl;  // 11
	cout << b << endl;  // 1
	cout << t - b << endl;
	system("pause");
	return 0;
}