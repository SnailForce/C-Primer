#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
template <typename Sequence> void print(Sequence const& seq)
{
	for (const auto& i : seq)
	{
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	vector<int> t1{ 1, 2, 3, 4 };
	list<int> t2;
	copy(t1.cbegin(), t1.cend(), back_inserter(t2));
	print(t2);

	vector<int> v;
	fill_n(back_inserter(v), 10, 0);
	print(v);

	return 0;
}