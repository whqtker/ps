#include <iostream>

using namespace std;

int n, m;
int cnt = 0;
int act[2][3]; // i: 정보 수집, 감시 / j: 수족관, 시청, 학교

void recur(int day, int p, int cur) {
	if (day == n) {
		if (cur >= m) {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i == p) {
			recur(day + 1, p, cur + act[0][p] / 2);
			recur(day + 1, p, cur + act[1][p] / 2);
		}
		else {
			recur(day + 1, i, cur + act[0][i]);
			recur(day + 1, i, cur + act[1][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> act[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			recur(1, j, act[i][j]);
		}
	}
	cout << cnt;
}