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
	// 合成的拷贝构造函数 未使用默认构造函数 unique不会变化
	return 0;
}