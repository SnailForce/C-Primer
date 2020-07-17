#include <bits/stdc++.h>
#include "mystrBlob.h"
using namespace std;
int main()
{
	const strBlob csb{ "hello", "world", "pezy" };
	strBlob sb{ "hello","world","Mooophy" };
	cout << csb.front() << " " << csb.back() << "\n";
	sb.back() = "pey";
	cout << sb.front() << " " << sb.back() << "\n";

	ifstream ifs("../../../data/book.txt");
	strBlob blob;
	string str;
	while (getline(ifs, str))
	{
		blob.push_back(str);
	}
	strBlobPtr it(blob.begin());
	strBlobPtr it2(blob.end());
	for (; it != it2; it.incr())
	{
		cout << it.deref() << " ";
	}
	return 0;
}
