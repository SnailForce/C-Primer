// 8.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
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
int main(int argc, char** argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	ofstream output(argv[2], ofstream::app);
	SalesData total;
	if (read(input, total))
	{
		SalesData trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else
	{
		cerr << "error" << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
