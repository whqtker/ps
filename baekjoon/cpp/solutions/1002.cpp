#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int test_case;
	cin >> test_case;

	int x1, y1, r1, x2, y2, r2;
	double distance;
	for (int i = 0; i < test_case; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); //(x1, y1), (x2, y2)ÀÇ °Å¸®

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << "\n";
			continue;
		}

		else if (x1 == x2 && y1 == y2 && r1 != r2)
		{
			cout << 0 << "\n";
			continue;
		}

		else if (r1 + r2 == distance || abs(r1 - r2) == distance)
			cout << 1 << "\n";

		else if (r1 + r2 > distance && abs(r1 - r2) < distance)
			cout << 2 << "\n";

		else if (r1 + r2 < distance || abs(r1 - r2) > distance)
			cout << 0 << "\n";
	}
}