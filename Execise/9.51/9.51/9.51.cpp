// 9.51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <array>
using namespace std;
class Data
{
private:
	unsigned year = 1970, month = 1, day = 1;
	unsigned monthFromName(const string& s = " ");
	array<string, 12> monthName{ "Jan", "Feb","Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
public:
	Data(const string& s = "");
	void print();
};
unsigned Data::monthFromName(const string& s)
{
	if (s.empty()) return 0;
	if (isdigit(s.at(0))) return stoi(s);
	for (auto i = 0; i != 12; ++i)
	{
		if (s.find(monthName.at(i)) != string::npos) return i + 1;
	}
	return 0;
}
Data::Data(const string & s)
{
	if (s.empty()) return;
	string delimiter{ " ,/" };
	auto pos = s.find_first_of(delimiter);
	if (pos == string::npos) throw invalid_argument("not supported");
	month = monthFromName(s.substr(0, pos));
	auto pos2 = s.find_first_of(delimiter, pos + 1);
	day = stoi(s.substr(pos + 1, pos2 - pos - 1));
	auto pos3 = s.find_last_of(delimiter);
	year = stoi(s.substr(pos3 + 1));
}
inline void Data::print()
{
	cout << year << "-" << month << "-" << day << endl;
}
int main()
{
	{
		auto data = Data();
		data.print();
	}
	{
		Data data("January 1,1900");
		data.print();
	}
	{
		auto data = Data("1/1/1990");
		data.print();
	}
	{
		auto data = Data("Jan 1 1900");
		data.print();
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
