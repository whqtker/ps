#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

string wheel[4];
int visited[4];

void clockwise(int idx) {
	wheel[idx] = wheel[idx][7] + wheel[idx];
	wheel[idx].erase(8);
}

void counterclockwise(int idx) {
	wheel[idx] = wheel[idx] + wheel[idx][0];
	wheel[idx].erase(0, 1);
}

void rotateWheel(int idx, int dir) {
	if (visited[idx])
		return;

	if (dir == -1) {
		visited[idx] = 1;

		if (idx - 1 >= 0 && wheel[idx][6] != wheel[idx - 1][2])
			rotateWheel(idx - 1, dir * -1);

		if (idx + 1 < 4 && wheel[idx][2] != wheel[idx + 1][6])
			rotateWheel(idx + 1, dir * -1);

		counterclockwise(idx);
	}
	else if (dir == 1) {
		visited[idx] = 1;

		if (idx - 1 >= 0 && wheel[idx][6] != wheel[idx - 1][2])
			rotateWheel(idx - 1, dir * -1);

		if (idx + 1 < 4 && wheel[idx][2] != wheel[idx + 1][6])
			rotateWheel(idx + 1, dir * -1);

		clockwise(idx);
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(visited, 0, sizeof(int) * 4);
		int idx, dir;
		cin >> idx >> dir;

		rotateWheel(idx - 1, dir);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += (wheel[i][0] - '0') * (int)pow(2, i);
	}

	cout << ans;
}