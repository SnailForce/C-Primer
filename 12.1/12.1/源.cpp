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
	void push_back(const string& £ô) { data->push_back(t); }
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
void strBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& strBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& strBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
int main()
{
	shared_ptr<vector<string>> p = make_shared<vector<string>>();
	cout << p.use_count() << "\n";
	return 0;
}