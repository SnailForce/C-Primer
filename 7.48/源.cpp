#include <iostream>
#include <string>
using namespace std;
class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(const string& s) : name(s) {}
	Sales_data& combine(const Sales_data&);
private:
	string name;
};
int main()
{
	auto u = static_cast<Sales_data>("123");
	string s = "123";
	u.combine(s);
	return 0;
}