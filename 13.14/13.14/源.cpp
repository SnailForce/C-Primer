#include <iostream>
using namespace std;
class numbered
{
public:
	numbered()
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
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	// 合成的拷贝构造函数 未使用默认构造函数 unique不会变化
	return 0;
}