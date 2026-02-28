#include <iostream>

using namespace std;

int ans[10];
int cnt = 0;

void bt(int k, int prev, int again, int score) {
	if (again >= 3)
		return;

	if (k == 10) {
		if (score >= 5)
			cnt++;
		return;
	}

	if (k == 0) {
		for (int i = 1; i <= 5; i++) {
			if (ans[0] == i)
				bt(1, i, 1, score + 1);
			else
				bt(1, i, 1, score);
		}
	}
	else {
		if (ans[k] == prev)
			bt(k + 1, prev, again + 1, score + 1);
		else
			bt(k + 1, prev, again + 1, score);

		for (int i = 1; i <= 5; i++) {
			if (prev != i) {
				if (ans[k] == i)
					bt(k + 1, i, 1, score + 1);
				else
					bt(k + 1, i, 1, score);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> ans[i];
	}

	bt(0, 0, 0, 0);
	cout << cnt;
}