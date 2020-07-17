#include <iostream>
using namespace std;
int main()
{
	char str1[] = "welcome to";
	char str2[] = "c++ family";
	cout << strlen(str1) << " " << strlen(str2) << endl;
	char res[21];
	strcpy_s(res, str1);
	strcat_s(res, str2);
	cout << res << endl;
	system("pause");
	return 0;
}