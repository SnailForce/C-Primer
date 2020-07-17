#include <iostream>
using namespace std;
int main()
{
	unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch, preCh = '\0';
	while (cin >> ch)
	{
		bool bl = true;
		if (preCh == 'f')
		{
			switch (ch)
			{
			case 'f':
				++ffCnt;
				bl = false;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			default:
				break;
			}
		}
		if (!bl)
		{
			preCh = '\0';
		}
		else
		{
			preCh = ch;
		}
	}
	system("pause");
	return 0;
}