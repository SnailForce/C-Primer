// 9.20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
	list<int> t1{ 1, 2,3,4,5,6,7,8,9,10,-1 };
	deque<int> r1, r2;
	for (auto i : t1)
	{
		if (i % 2 == 0)
		{
			r1.push_back(i);
		}
		else
		{
			r2.push_back(i);
		}
	}
	cout << "oushu: ";
	for (auto i : r1)
	{
		cout << i << " ";
	}
	cout << "\njishu: ";
	for (auto i : r2)
	{
		cout << i << " ";
	}
	cout << endl;
	int i = 0;
	const int ci = i;
	const int& cr = ci;
	auto& c = cr;
	c = 2;
	i = 4;
	cout << i << " " << ci << " " << cr << " " << c << endl;

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
