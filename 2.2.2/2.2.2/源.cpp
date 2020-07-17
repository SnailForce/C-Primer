#include <iostream>
int sum()
{
	// extern int t = 0;
	// return t;
	return 0;
}
int main()
{
	int val = 1024;
	int &t = val;
	std::cout << val << t << std::endl;
	++t;
	std::cout << val << t << std::endl;
	int &val1 = t;
	std::cout << val << t << val1 << std::endl;
	std::cout << "2.3.2" << std::endl;
	int q1 = 42;
	int *p1 = &q1;
	std::cout << q1 << p1 << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << "===========================" << std::endl;
	int a = 20;
	int *f1 = &a;
	int *f2 = f1;
	std::cout << *f1 << " " << f1 << " " << *f2 << " " << f2 << std::endl;
	int e1 = 0, e2 = 1;
	int *w1 = &e1, *w2 = w1;
	w1 = &e2;
	++e2;
	std::cout << *w1 << e2 << std::endl;
	*w1 = e2;
	++e2;
	std::cout << *w1 << e2 << std::endl;
	system("pause");
	return 0;
}