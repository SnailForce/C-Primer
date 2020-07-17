#include <iostream>
using namespace std;
int main()
{
	char ca[] = { 'c','+','+' ,'\0' };
	char* p = ca;
	while (*p)
	{
		cout << *p << endl;
		++p;
	}
	cout << strlen(ca) << endl;  // 3
	system("pause");
	return 0;
}