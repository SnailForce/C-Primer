#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> t{ 1,2,3,4,5 };
	fill_n(t.begin(), t.size(), 0);
}