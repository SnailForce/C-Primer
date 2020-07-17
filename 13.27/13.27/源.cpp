#include <iostream>
using namespace std;
class HasPtr
{
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}	
	HasPtr(const HasPtr& h) : ps(h.ps), i(h.i), use(h.use) { ++* use; }
	HasPtr& operator=(const HasPtr& h)
	{
		++* h.use;
		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
		ps = h.ps;
		i = h.i;
		use = h.use;
		return *this;
	}
	~HasPtr()
	{
		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
	}
	friend void swap(HasPtr&, HasPtr&);
private:
	string* ps;
	int i;
	size_t* use;
};
inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}