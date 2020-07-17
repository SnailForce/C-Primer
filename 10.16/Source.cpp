#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void elimdups(vector<string>& vs)
{
	sort(vs.begin(), vs.end());
	auto e = unique(vs.begin(), vs.end());
	vs.erase(e, vs.end());
}
void biggies(vector<string>& vs, size_t sz)
{
	elimdups(vs);
	for (auto u : vs) { cout << u << " "; }
	cout << endl;
	stable_sort(vs.begin(), vs.end(), [](const string& s1, const string& s2)->bool {return s1.size() < s2.size(); });
	auto wc = find_if(vs.begin(), vs.end(), [sz](const string& s) -> bool {return s.size() >= sz; });
	auto w2 = partition(vs.begin(), vs.end(), [sz](const string& s) -> bool {return s.size() < sz; });
	for_each(w2, vs.end(), [](const string& s) {cout << s << " "; });
}
int main()
{
	vector<string> v{ "1234", "1234", "hi~", "alan", "cp" };
	biggies(v, 3);
	cout << endl;
	return 0;
}