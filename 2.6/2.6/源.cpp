#include <iostream>
#include <string>
using namespace std;
struct SalesData
{
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0.0;
};
int main()
{
	/*
	string s1("value");
	cout << sizeof(s1) << endl;  // 28
	cout << s1.size() << endl;  // 5
	string s2(10, 'a');
	cout << s2 << endl;
	string s3;
	cin >> s3;
	cout << s3 << endl;
	*/
	string s = ",";
	string s1 = "hello" + s + "world";
	string line;
	while (getline(cin, line))
	{
		if (!line.empty())
		{
			cout << line.size() << ":" << line << endl;
		}
	}
	string word;
	while (cin >> word)
	{
		cout << word << endl;
	}
	system("pause");
	return 0;
}