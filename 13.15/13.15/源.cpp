#include <iostream>
using namespace std;
class numbered
{
public:
	numbered()
	{
		mysn = unique++;
	}
	numbered(const numbered& n)
	{
		mysn = unique++;
	}
	int mysn;
	static int unique;
};
int numbered::unique = 10;
void f(numbered s)
{
	cout << s.mysn << endl;
}
int main()
{
	numbered a, b = a, c = b;  // 10 11 12
	f(a); // 13
	f(b); // 14
	f(c); // 15
	// �ϳɵĿ������캯�� δʹ��Ĭ�Ϲ��캯�� unique����仯
	return 0;
}