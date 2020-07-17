// 8.13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct personInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string& t)
{
	return isdigit(t[0]);
}

string format(const string& t)
{
	return t.substr(0, 3) + '-' + t.substr(3, 6) + '-' + t.substr(6);
}

int main()
{
	ifstream is("../../../data/phonenumbers.txt");
	string line, word;
	vector<personInfo> ss;
	if (is.is_open())
	{
		while (getline(is, line))
		{
			istringstream record(line);
			personInfo t;
			record >> t.name;
			while (record >> word)
			{
				t.phones.push_back(word);
			}
			ss.push_back(t);
		}
		for (const auto& t : ss)
		{
			ostringstream formatted, badNums;
			for (const auto& nums : t.phones)
			{
				if (!valid(nums))
				{
					badNums << " " << nums;
				}
				else
				{
					formatted << " " << format(nums);
				}
			}
			if (badNums.str().empty())
			{
				cout << t.name << formatted.str() << endl;
			}
			else
			{
				cout << "error: " << t.name << badNums.str() << endl;
			}
		}
	}
	else
	{
		cerr << "error" << endl;
		return -1;
	}
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
