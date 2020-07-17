// 10.11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using namespace std::placeholders;
void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto end = unique(words.begin(), words.end());
	words.erase(end, words.end());
}
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
void print(vector<string>& words)
{
	for (const auto& c : words)
	{
		cout << c << " ";
	}
	cout << "\n";
}
inline bool func(const string & s, string::size_type sz)
{
	return s.size() >= sz;
}
inline void func1(const string& s)
{
	cout << s << " ";
}
void biggies(vector<string>& words, string::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string & s1, const string & s2) {return s1.size() < s2.size(); });
	auto it = find_if(words.begin(), words.end(), [sz](const string & s) {return s.size() > sz; });
	auto count = words.end() - it;
	cout << count << "word(s)\n";
	for_each(it, words.end(), [](const string & s) {cout << s << " "; });
	cout << "\n";
}
void biggiesConstruct(vector<string>& words, string::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string & s1, const string & s2) {return s1.size() < s2.size(); });
	auto it = partition(words.begin(), words.end(), [sz](const string & s) {return s.size() >= sz; });
	auto count = it - words.begin();
	cout << count << "word(s)\n";
	for_each(words.begin(), it, [](const string & s) {cout << s << " "; });
	cout << "\n";
}
void biggiesConstructStable(vector<string>& words, string::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string & s1, const string & s2) {return s1.size() < s2.size(); });
	auto it = stable_partition(words.begin(), words.end(), [sz](const string & s) {return s.size() >= sz; });
	auto count = it - words.begin();
	cout << count << "word(s)\n";
	for_each(words.begin(), it, [](const string & s) {cout << s << " "; });
	cout << "\n";
}
void biggiesBind(vector<string>& words, string::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string & s1, const string & s2) {return s1.size() < s2.size(); });
	auto it = stable_partition(words.begin(), words.end(), bind(func, _1, sz));
	auto count = it - words.begin();
	cout << count << "word(s)\n";
	for_each(words.begin(), it, bind(func1, _1));
	cout << "\n";
}
int main()
{
	vector<string> words{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	print(words);
	elimDups(words);
	print(words);
	stable_sort(words.begin(), words.end(), isShorter);
	stable_sort(words.begin(), words.end(), [](const string & s1, const string & s2) {return s1.size() < s2.size(); });
	print(words);
	cout << string(20, '*') << "\n";
	biggies(words, 4);
	biggies(words, 3);
	biggiesConstruct(words, 4);
	biggiesConstruct(words, 3); 
	biggiesConstructStable(words, 4);
	biggiesConstructStable(words, 3);
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
