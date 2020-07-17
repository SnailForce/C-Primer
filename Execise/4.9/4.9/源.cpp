#include <iostream>
using namespace std;
int main()
{
	string s = { '\0' };
	cout << s.size() << " " << s << endl;
	const char* cp = "";
	if (*cp)
	{
		cout << 2 << endl;
	}
	system("pause");
	return 0;
}