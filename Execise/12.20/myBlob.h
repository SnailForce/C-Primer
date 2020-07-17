#pragma once
#ifndef MYSTRBLOB_H
#define MYSTRBLOB_H
#include <bits/stdc++.h>
using namespace std;
class strBlobPtr;
class strBlob
{
  public:
	using size_type = vector<string>::size_type;
	friend class strBlobPtr;
	strBlob();
	strBlob(initializer_list<string> l);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string &front();
	string &back();
	string &front() const;
	string &back() const;
	strBlobPtr begin();
	strBlobPtr end();

  private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};
strBlob::strBlob() : data(make_shared<vector<string>>()) {}
strBlob::strBlob(initializer_list<string> l) : data(make_shared<vector<string>>(l)) {}

void strBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string &strBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string &strBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

string &strBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string &strBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}


class strBlobPtr
{
  public:
	strBlobPtr() : curr(0) {}
	strBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string &deref() const
	{
		auto p = check(curr, "end");
		return (*p)[curr];
	}
	strBlobPtr &incr()
	{
		auto p = check(curr, "end of strBlob");
		++curr;
		return *this;
	}
	bool operator!=(const strBlobPtr &p)
	{
		return p.curr != curr;
	}

  private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	shared_ptr<vector<string>> check(size_t sz, const string &msg) const
	{
		auto ret = wptr.lock();
		if (!ret)
		{
			throw runtime_error("unbound strBlob");
		}
		if (sz >= ret->size())
		{
			throw out_of_range(msg);
		}
		return ret;
	}
};
strBlobPtr strBlob::begin()
{
	return strBlobPtr(*this);
}
strBlobPtr strBlob::end()
{
	auto ret = strBlobPtr(*this, data->size());
	return ret;
}
#endif