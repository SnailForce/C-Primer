#include <iostream>
using namespace std;
int main()
{
	int q = 0x71;
	q = ~q << 6;
	cout << q << endl;
	system("pause");
	return 0;
}