#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void wordTransform(ifstream&, ifstream&);
map<string, string> buildMap(ifstream&);
const string& transform(const string&, const map<string, string>&);
int main()
{
	ifstream ifsMap("../../../data/word_transformation.txt");
	ifstream ifsContent("../../../data/given_to_transform.txt");
	if (ifsMap && ifsContent)
	{
		wordTransform(ifsMap, ifsContent);
	}
	else
	{
		cerr << "Can't find the documents\n";
	}
	return 0;
}
map<string, string> buildMap(ifstream& mapFile)
{
	map<string, string> transMap;
	string key, value;
	while (mapFile >> key && getline(mapFile, value))
	{
		if (value.size() > 1)
		{
			transMap[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
		}
	}
	return transMap;
}
const string& transform(const string& s, const map<string, string>& m)
{
	auto mapIt = m.find(s);
	return mapIt == m.cend() ? s : mapIt->second;
}
void wordTransform(ifstream& ifsMap, ifstream& ifsContent)
{
	auto transMap = buildMap(ifsMap);
	string text;
	while (getline(ifsContent, text))
	{
		istringstream is(text);
		string word;
		while (is >> word)
		{
			cout << transform(word, transMap) << " ";
		}
		cout << "\n";
	}
}
