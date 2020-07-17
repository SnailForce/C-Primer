#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int curCnt = 1;
	int maxCnt = 0;
	string preString;
	string curString;
	string maxString;
	while (cin >> curString)
	{
		if (curString == preString)
		{
			++curCnt;
			if (curCnt > maxCnt)
			{
				maxCnt = curCnt;
				maxString = curString;
			}
		}
		else
		{
			curCnt = 1;
		}
		preString = curString;
	}
	cin.clear();
	cin.sync();
	cout << maxCnt << " " << maxString << endl;
	system("pause");
	return 0;
}