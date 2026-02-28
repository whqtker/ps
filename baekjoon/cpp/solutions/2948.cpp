#include <iostream>

using namespace std;

int main() {
	int d, m;
	cin >> d >> m; // m월 d일

	int tot = d; // 1월 1일로부터 몇 일 떨어져있는지
	for (int i = 1; i < 12; i++) {
		if (m > i) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
				tot += 31;
			else if (i != 2)
				tot += 30;
			else
				tot += 28;
		}
	}

	switch (tot % 7) {
	case 1:
		cout << "Thursday";
		break;
	case 2:
		cout << "Friday";
		break;
	case 3:
		cout << "Saturday";
		break;
	case 4:
		cout << "Sunday";
		break;
	case 5:
		cout << "Monday";
		break;
	case 6:
		cout << "Tuesday";
		break;
	case 0:
		cout << "Wednesday";
		break;
	}
}