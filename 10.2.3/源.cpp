#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void fun(vector<string>&);
bool isShorter(const string&, const string&);
template <typename Sequence> inline void println(Sequence const& seq)
{
	for (const auto& u : seq)
	{
		cout << u << " ";
	}
	cout << endl;
}
int main()
{
	vector<string> tmp{ "fox", "jumps", "over", "quick", "red", "fox", "slow", "the", "turtle" };
	fun(tmp);
	println(tmp);
	stable_sort(tmp.begin(), tmp.end(), isShorter);
	println(tmp);
	return 0;
}
void fun(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto t = unique(words.begin(), words.end());
	words.erase(t, words.end());
}
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}