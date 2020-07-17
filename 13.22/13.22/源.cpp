#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class HasPtr
{
public:
	HasPtr(const string& ss = string()) : s(new string(ss)), t(0) {}
	HasPtr(const HasPtr& h) : s(new string(*h.s)), t(h.t) {}
	HasPtr& operator=(const HasPtr& h)
	{
		t = h.t;
		auto newp = new string(*h.s);
		delete s;
		s = newp;
		return *this;
	}
	~HasPtr()
	{
		delete s;
	}
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
public:
	int t;
	string* s;
};
inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.t, rhs.t);
	swap(lhs.s, rhs.s);
	cout << "call swap" << endl;
}
inline bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
	return *lhs.s < *rhs.s;
}
void show(vector<HasPtr>& vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *(it->s) << endl;
	}
}
int main()
{
	vector<HasPtr> test;
	test.push_back(HasPtr("as"));
	test.push_back(HasPtr("we"));
	test.push_back(HasPtr("ghome"));
	sort(test.begin(), test.end());
	show(test);
	return 0;
}