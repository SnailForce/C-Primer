#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int grade  = 0;
	string score;
	vector<string> scores{ "f","d","c","b","a","a++" };
	for (auto& c : scores)
	{
		for (auto& t : c)
		{
			t = toupper(t);
		}
	}
	while (cin >> grade)
	{
		// cout << ((score < 60) ? scores[0] : scores[(score - 50) / 10]) << endl;
		if (grade < 60)
		{
			score = scores[0];
		}
		else
		{
			score = scores[(grade - 50) / 10];
			if (grade != 100)
			{
				if (grade % 10 > 7)
				{
					score += "+";
				}
				else if (grade % 10 < 3)
				{
					score += "-";
				}
			}
		}
		cout << score << endl;
	}
	cin.clear();
	cin.sync();
	system("pause");
	return 0;
}