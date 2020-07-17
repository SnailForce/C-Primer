# include <iostream>
using namespace std;
int main()
{
	
	cout << "--------------" << endl;
	char const * p1 = "aaa";
	char const * p2 = p1;
	p1 = "bbb";
	cout << p1 << endl;
	cout << p2 << endl;
	system("pause");
	/*
	cout << "--------------" << endl;
	char * const s = "aaaaaaaa";
	char t[] = "aaaaaaaa";
	char * const p2 = t;
	char * const p3 = p2;
	cout << p2 << endl;
	cout << p3 << endl;
	p2[0] = 's';
	cout << p2 << endl;
	cout << p3 << endl;
	*/
	/*
	char t[] = "aaaaaaaa";
	char * const p2 = t;
	p2[0] = 's';
	cout << p2 << endl;
	system("pause");
	*/
	/*
	char t[] = "sss";
	char const * s = t;
	//s[0] = 'q';
	t[0] = 'q';
	cout << s << endl << t << endl;
	system("pause");
	*/
	return 0;
}