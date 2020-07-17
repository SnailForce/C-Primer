#include <iostream>
using namespace std;
int main()
{
	string str("some string");
	for (auto s : str)
	{
		cout << s << endl;
	}
	//  统计标点符号
	string s("hello world !!!");
	decltype(s.size()) punctCnt = 0;
	for (auto c : s)
	{
		if (ispunct(c))
		{
			++punctCnt;
		}
	}
	cout << punctCnt << endl;
	// 大写
	for (auto& c : s)
	{
		c = toupper(c);
	}
	cout << s << endl;
	// 第一个单词大写
	string s1("nihao zhihua");
	for (decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]); ++index)
	{
		s1[index] = toupper(s1[index]);
	}
	cout << s1 << endl;
	const string hexdigits = "0123456789ABCDEF";
	string res;
	decltype(res.size()) n;
	while (cin >> n)
	{
		if (n < hexdigits.size())
		{
			res += hexdigits[n];
		}
	}
	system("pause");
	return 0;
}