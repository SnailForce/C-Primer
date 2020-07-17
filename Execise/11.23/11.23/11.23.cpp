// 11.23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<string, vector<string>> m1;
	multimap<string, string> m2;
	multimap<string, string> m3;
	string f, last, first;
	while (cin >> last >> first)
	{
		m1[last].push_back(first);
		m2.emplace(last, first);
		m3.insert({ last, first });
	}
	for (auto c : m1)
	{
		cout << c .first << " ";
		for (auto s : c.second)
		{
			cout << s << " ";
		}
	}
	cout << "\n";
	for (auto c : m2)
	{
		cout << c.first << " " << c.second;
	}
	cout << "\n";
	for (auto c : m3)
	{
		cout << c.first << " " << c.second;
	}
	cout << "\n";
	map<string, string> s;
	s.at("2") = "@";
	const map<string, string> s1;
	s1.at("2") = "@";
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
