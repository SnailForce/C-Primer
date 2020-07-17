#include <iostream>
using namespace std;
int main()
{
	string preString, curString;
	bool res = false;
	while (cin >> curString)
	{
		if (curString == preString)
		{
			res = true;
			cout << "We find\n";
			break;
		}
		else
		{
			preString = curString;
		}
	}
	if (!res)
	{
		cout << "We not find\n";
	}
	system("pause");
	return 0;
}