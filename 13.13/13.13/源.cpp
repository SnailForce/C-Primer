#include <iostream>
#include <vector>
using namespace std;
struct X
{
	X()
	{
		cout << "X()" << endl;
	}
	X(const X&)
	{
		cout << "X(const X&)" << endl;
	}
	~X()
	{
		cout << "~X()" << endl;
	}
	X& operator= (const X& rhs)
	{
		cout << "operator= X(rhs)" << endl;
		return *this;
	}
private:
	int i;
};
void f(const X& rx, X x)
{
	vector<X> vec;
	vec.reserve(2); // allocate space
	vec.push_back(rx);
	vec.push_back(x);
}
int main()
{
	X* px = new X;
	f(*px, *px); // �ڶ�������Ҫ���п������캯��
	// �������������������������
	delete px;
	// delete�����һ����������
	return 0;
}