#include <iostream>
using namespace std;
int main()
{
	int i = 10;
	int& t = i;
	int j = 20;
	t = j;
	cout << i << " " << j << endl << t << endl;
	j = 30;
	cout << i << " " << j << endl << t << endl;
	return 0;
}
// https://www.zhihu.com/question/324073089/answer/681011987