#include <iostream>
using namespace std;
int main()
{
	string str("some string");
	for (auto s : str)
	{
		cout << s << endl;
	}
	//  ͳ�Ʊ�����
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
	// ��д
	for (auto& c : s)
	{
		c = toupper(c);
	}
	cout << s << endl;
	// ��һ�����ʴ�д
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