// 7.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class SalesData
{
	friend istream& read(istream&, SalesData&);
	friend ostream& print(ostream&, const SalesData&);
	friend SalesData add(const SalesData&, const SalesData&);

private:
	string bookNo;
	unsigned unitsSold = 0;
	double sellingPrice = 0.0;
	double salePrice = 0.0;
	double discount = 0.0;
	double revenue = 0.0;
public:
	SalesData() = default;
	SalesData(const string& book) :bookNo(book) {}
	SalesData(const string&, const unsigned, const double, const double);
	SalesData(istream& is)
	{
		read(is, *this);
	}
	string isbn() const
	{
		return bookNo;
	}
	SalesData& combine(const SalesData& rhs)
	{
		unitsSold += rhs.unitsSold;
		salePrice = (rhs.salePrice * rhs.unitsSold + salePrice * unitsSold) / (rhs.unitsSold + unitsSold);
		if (sellingPrice != 0)
		{
			discount = salePrice / sellingPrice;
			return *this;
		}
	}
private:
	double avgPrice() const
	{
		return unitsSold ? revenue / unitsSold : 0;
	}
	// istream& read(istream&, SalesData&);
	// ostream& print(ostream&, SalesData&);
	// SalesData add(const SalesData&, const SalesData&);
};

SalesData::SalesData(const string& book, const unsigned num, const double sellp, const double salep)
{
	bookNo = book;
	unitsSold = num;
	sellingPrice = sellp;
	salePrice = salep;
	if (sellingPrice != 0)
	{
		discount = salePrice / sellingPrice;
	}
}

istream& read(istream& is, SalesData& item)
{
	double price = 0;
	is >> item.bookNo >> item.unitsSold >> price;
	item.revenue = price * item.unitsSold;
	return is;
}
ostream& print(ostream& os, SalesData& item)
{
	os << item.isbn() << item.unitsSold << " " << item.revenue << " " << item.avgPrice;
	return os;
}
SalesData add(const SalesData& t1, const SalesData& t2)
{
	SalesData sum = t1;
	sum.combine(t2);
	return sum;
}

int main()
{
	std::cout << "Hello World!\n";
	SalesData total;
	if (read(cin, total))
	{
		SalesData trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "error" << endl;
		return -1;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
