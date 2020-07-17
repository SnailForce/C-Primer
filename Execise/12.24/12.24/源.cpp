#include <bits/stdc++.h>
using namespace std;
int main()
{
	int size{ 0 };
	cin >> size;
	cin.ignore();
	char* t = new char[size + 1];
	cin.get(t, size + 1);
	cout << t << "\n";
	delete[] t;
	return 0;
}