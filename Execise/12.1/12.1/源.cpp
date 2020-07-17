#include <bits/stdc++.h>
using namespace std;
class strBlob
{
public:
	using size_type = vector<string>::size_type;
	strBlob();
	strBlob(initializer_list<string> l);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& t) { data->push_back(t); }
	void pop_back();
	string& front();
	string& back();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const
	{
		if (i >= data->size()) throw std::out_of_range(msg);
	}
};
strBlob::strBlob() : data(make_shared<vector<string>>()) {}
strBlob::strBlob(initializer_list<string> l) : data(make_shared<vector<string>>(l)) {}
void strBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
string& strBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string& strBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
int main()
{
	strBlob b1;
	{
		strBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << " " << b2.size();
	}
}