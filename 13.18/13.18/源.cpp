#include <iostream>
using namespace std;
static int j;
class Employee
{
public:
	Employee() : id_(i++) {}
	Employee(const string& s) : name(s), id_(i++) {}
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
	const int id()
	{
		return id_;
	}
private:
	string name;
	int id_;
	static int i;
};
int Employee::i = 0;
int main()
{
	cout << j << endl;
	return 0;
}