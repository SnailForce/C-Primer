#include <bits/stdc++.h>
using namespace std;
vector<int>* dynamicGenerator()
{
	vector<int>* p = new vector<int>();
	return p;
}
void dynamicProcessor(vector<int>* p)
{
	int i;
	while (cin >> i)
	{
		p->push_back(i);
	}
}
void dynamicPrinter(vector<int>* p)
{
	for (const auto& c : *p)
	{
		cout << c << " ";
	}
	cout << "\n";
}
shared_ptr<vector<int>> dynamicGenerator_s()
{
	return make_shared<vector<int>>();
}
void dynamicProcessor_s(shared_ptr<vector<int>> p)
{
	int i;
	while (cin >> i)
	{
		p->push_back(i);
	}
}
void dynamicPrinter_s(const shared_ptr<vector<int>> p)
{
	for (const auto& c : *p)
	{
		cout << c << " ";
	}
	cout << "\n";
}
int main()
{
	vector<int>* p = dynamicGenerator();
	dynamicProcessor(p);
	dynamicPrinter(p);
	delete p;
	auto p1 = dynamicGenerator_s();
	dynamicProcessor_s(p1);
	dynamicPrinter_s(p1);
	return 0;
}