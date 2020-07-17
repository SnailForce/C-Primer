// 12.27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <bits/stdc++.h>
using namespace std;
class queryResult;
class textQuery
{
public:
	using lineNo = vector<string>::size_type;
	textQuery(ifstream&);
	queryResult query(const string&) const;
private:
	shared_ptr<vector<string>> input;
	map<string, shared_ptr<set<lineNo>>> result;
};
textQuery::textQuery(ifstream& ifs) : input(new vector<string>)
{
	lineNo lineno{ 0 };
	string line;
	while (getline(ifs, line))
	{
		input->push_back(line);
		int n = input->size() - 1;
		istringstream is(line);
		string word;
		while (is >> word)
		{
			auto& lines = result[word];
			if (!lines)
			{
				lines.reset(new set<lineNo>);
			}
			lines->insert(n);
		}
	}
}
class queryResult
{
public:
	friend ostream& print(ostream&, const queryResult&);
	queryResult(const string& s, shared_ptr<set<textQuery::lineNo>> ss, shared_ptr<vector<string>> v) : word(s), nos(ss), input(v) {}
private:
	string word;
	shared_ptr<set<textQuery::lineNo>> nos;
	shared_ptr<vector<string>> input;
};
queryResult textQuery::query(const string& s) const
{
	static shared_ptr<set<lineNo>> nodata(new set<lineNo>);
	auto loc = result.find(s);
	if (loc == result.end())
	{
		return queryResult(s, nodata, input);
	}
	else
	{
		return queryResult(s, loc->second, input);
	}
}
ostream& print(ostream& out, const queryResult& qr)
{
	out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times\n" : " time\n");
	for (auto i : *qr.nos)
	{
		out << "\t( line " << i + 1 << " ) " << qr.input->at(i) << "\n";
		out << "\t( line " << i + 1 << " ) " << *(qr.input->begin() + i) << "\n";
	}
	return out;
}
void runQueries(ifstream& infile)
{
	textQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (cin >> s && s != "q")
		{
			print(cout, tq.query(s));
		}
		else
		{
			break;
		}
	}
}
int main()
{
	ifstream ifs("../../../data/storyDataFile.txt");
	runQueries(ifs);
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
