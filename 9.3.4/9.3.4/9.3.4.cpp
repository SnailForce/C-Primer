// 9.3.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
	forward_list<int> t{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = t.before_begin();
	auto curr = t.begin();
	while (curr != t.end())
	{
		if (*curr & 1)
		{
			curr = t.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	for (auto i : t)
	{
		cout << i << " ";
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
