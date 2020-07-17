// 9.28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <forward_list>
#include <string>
using namespace std;
void func(forward_list<string>& t, const string& s1, const string& s2)
{
	auto prev = t.before_begin();
	auto size = distance(t.begin(), t.end());
	for (auto curr = t.begin(); curr != t.end(); prev = curr++)
	{
		if (*curr == s1)
		{
			curr = t.insert_after(curr, s2);
		}
	}
	if (size == distance(t.begin(), t.end()))
	{
		t.insert_after(prev, s2);
	}
}
int main()
{
	forward_list<string> list1(4, "sadi");
	string a = "sadi";
	string b = "sadi";
	func(list1, a, b);
	for (auto it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
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
