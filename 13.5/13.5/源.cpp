#include <iostream>
using namespace std;
class HasPtr
{
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0){}
	HasPtr(const HasPtr& hp)
	{
		ps = new string(*hp.ps);
		i = hp.i;
	}
	HasPtr& operator= (const HasPtr& hp)
	{
		string* p = new string(*hp.ps);
		delete ps;
		ps = p;
		i = hp.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	string *ps;
	int i;
};
int main()
{
	int* p = new int(5);
	cout << p << endl;
	cout << *p << endl;
	delete p;
	cout << p << endl;
	// cout << *p << endl;
	p = new int(10);
	cout << p << endl;
	cout << *p << endl;
	// https://stackoverflow.com/questions/33374483/what-does-visual-studio-do-with-a-deleted-pointer-and-why
	return 0;
}
