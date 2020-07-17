
// 12.28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream ifs("../../../data/letter.txt");
	vector<string> input;
	map<string, set<decltype(input.size())>> dictionary;
	decltype(input.size()) lineNo{ 0 };
	string line;
	while (getline(ifs, line))
	{
		cout << line << "\n";
		input.push_back(line);
		istringstream is(line);
		string text;
		string word;
		while (is >> text)
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			dictionary[word].insert(lineNo);
			// word.clear();
		}
		++lineNo;
	}
	while (true)
	{
		cout << "enter word to look for, or q to quit:\n";
		string s;
		if (cin >> s && s != "q")
		{
			auto it = dictionary.find(s);
			if (it != dictionary.end())
			{
				cout << s << " occurs " << it->second.size() << (it->second.size() > 1 ? " times\n" : " time\n");
				for (auto i : it->second)
				{
					cout << "\t( line " << i + 1 << " ) " << input.at(i) << "\n";
				}
			}
			else
			{
				cout << s << " occurs 0 time\n";
			}
		}
		else
		{
			break;
		}
	}
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
