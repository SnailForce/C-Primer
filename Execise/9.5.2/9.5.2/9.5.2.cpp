
// 9.5.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
void Replace(string& s, const string& oldVal, const string& newVal)
{
	auto l = oldVal.size();
	if (!l)
	{
		return;
	}
	for (auto it = s.begin(); it <= s.end() - l;)
	{
		auto it1 = it;
		auto it2 = oldVal.begin();
		while (it2 != oldVal.end() && *it1 == *it2)
		{
			++it1;
			++it2;
		}
		if (it2 == oldVal.end())
		{
			it = s.erase(it, it1);
			if (newVal.size())
			{
				it = s.insert(it, newVal.begin(), newVal.end());
				it += newVal.size();
			}
		}
		else
		{
			++it;
		}
	}
}
void Replace2(string& s, const string& oldVal, const string& newVal)
{
	int p = 0;
	while ((p = s.find(oldVal, p)) != string::npos)
	{
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}
}
void Replace3(string& s, const string& oldVal, const string& newVal)
{
	for (decltype(s.size()) i = 0; i <= s.size() - oldVal.size(); ++i)
	{
		if (s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size() - 1;
		}
	}
}
void func(string& s, const string& s1, const string& s2)
{
	s.insert(s.begin(), s1.begin(), s1.end());
	s.append(s2);
}
void func1(string& s, const string& s1, const string& s2)
{
	s.insert(0, s1);
	s.insert(s.size(), s2);
}
int main()
{
	string str{ "To drive straight thru is a foolish, tho courageous act." };
	Replace3(str, "tho", "though");
	cout << str << endl;
	Replace3(str, "thru", "through");
	cout << str << endl;
	string ss{ "lan" };
	string sss(2, 't');
	cout << ss << sss << endl;
	func(ss, "Mr.", "Jr.");
	cout << ss << endl;
	func1(ss, "Mr.", "Jr.");
	cout << ss << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
