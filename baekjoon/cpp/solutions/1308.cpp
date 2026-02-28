#include <iostream>

using namespace std;

int main() {
	int y1, m1, d1, y2, m2, d2;
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

	if (y2 - y1 > 1000 || y2 - y1 == 1000 && m2 - m1 >= 0 && d2 - d1 >= 0) {
		cout << "gg";
	}
	else {
		// 년월일을 년일로 바꾸고, 년을 통일시킨다. 그 후 일끼리 뺀다.
		int n = 0, m = 0;

		// 12월은 계산에 포함하지 않는다.
		for (int i = 1; i < 12; i++) {
			if (i < m1) {
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
					n += 31;
				else if (i != 2)
					n += 30;
				else {
					if ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0)
						n += 29;
					else
						n += 28;
				}
			}
		}
		n += d1;

		for (int i = 1; i < 12; i++) {
			if (i < m2) {
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
					m += 31;
				else if (i != 2)
					m += 30;
				else {
					if ((y2 % 4 == 0 && y2 % 100 != 0) || y2 % 400 == 0)
						m += 29;
					else
						m += 28;
				}
			}
		}
		m += d2;

		for (int i = y2 - 1; i >= y1; i--) {
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				m += 366;
			else
				m += 365;
		}
		cout << "D-" << m - n;
	}
}