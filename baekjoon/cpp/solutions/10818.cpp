#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {

	int	cnt;
	cin >> cnt;

	int a;
	int max = 0;
	int min = 0;
	for (int i = 0; i < cnt; i++)
	{
		cin >> a;

		if (i == 0)
		{
			max = a;
			min = a;
		}

		if (a > max)
			max = a;
		else if (a < min)
			min = a;
	}

	cout << min << " " << max;
}