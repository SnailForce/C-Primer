#include <bits/stdc++.h>
#include "myBlob.h"
using namespace std;
int main()
{
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
    cout << "\n";
    return 0;
}