#include <iostream>
#include <vector>
using namespace std;
struct MyStruct
{
	int num = 0;
	string s;
};
int main()
{
	MyStruct w1, w2;
	char* p;
	int t[]{ 1,2,3,4,5,6,7,8,9 };
	vector<int> t2{ 2,2,3,4,5,6 }, t3{ 1,1 };
	cout << sizeof w1 << sizeof MyStruct << sizeof w1.num << sizeof MyStruct::s << endl;
	cout << sizeof * p << sizeof p << endl;
	cout << 5[t] << " " << sizeof t << endl;
	cout << sizeof t2 << " " << sizeof t3 << endl;
	system("pause");
	return 0;
}