#include <iostream>
int main()
{
	int t1 = 0;
	int t2 = 0;
	if (std::cin >> t1)
	{
		int cnt = 1;
		while (std::cin >> t2)
		{
			if (t1 == t2)
			{
				++cnt;
			}
			else
			{
				std::cout << t1 << " " << cnt << std::endl;
				t1 = t2;
				cnt = 1;
			}
		}
		std::cout << t1 << " " << cnt << std::endl;
	}
	system("pause");
	return 0;
}