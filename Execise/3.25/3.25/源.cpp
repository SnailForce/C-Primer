#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
	char tt[] = "hello";
	cout << strlen(tt) << endl;  // 5
	cout << sizeof(tt) << " " << sizeof(tt[0]) << endl;  // 6 1
	cout << sizeof(int) << endl;  // 4
	srand((unsigned)time(NULL));
	vector<unsigned> vUS(11);
	for (int i = 0; i < 10; ++i)
	{
		auto t = rand() % 101;
		cout << t << " ";
		++vUS.at(t / 10);
	}
	cout << endl;
	for (auto c : vUS)
	{
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}