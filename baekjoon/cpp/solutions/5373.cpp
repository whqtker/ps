#include <iostream>

using namespace std;

char cube[6][3][3]; // 위, 아래, 앞, 뒤, 왼, 오
char colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = colors[i];
			}
		}
	}
}

// a->b->c->d->a
void cycle(char& a, char& b, char& c, char& d) {
	char temp = d;
	d = c;
	c = b;
	b = a;
	a = temp;
}
// 면을 시계 방향으로 회전
void rotate(int x) {
	// 현재 면 회전
	char tmp[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = cube[x][i][j];

	// 시계방향으로 회전하면 (i, j) -> (j, 2-i)
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cube[x][j][2 - i] = tmp[i][j];

	// 인접 면 회전
	// 윗면: 0행, 2-4-3-5
	if (x == 0) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[2][0][i], cube[4][0][i], cube[3][0][i], cube[5][0][i]);
		}
	}
	// 아랫면: 2행, 2-5-3-4
	else if (x == 1) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[2][2][i], cube[5][2][i], cube[3][2][i], cube[4][2][i]);
		}
	}
	// 앞면: 0-5-1-4
	else if (x == 2) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[0][2][i], cube[5][i][0], cube[1][0][2 - i], cube[4][2 - i][2]);
		}
	}
	// 뒷면: 0-4-1-5
	else if (x == 3) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[0][0][2 - i], cube[4][i][0], cube[1][2][i], cube[5][2 - i][2]);
		}
	}
	// 왼쪽: 0-2-1-3
	else if (x == 4) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[0][i][0], cube[2][i][0], cube[1][i][0], cube[3][2 - i][2]);
		}
	}
	// 오른쪽: 0-3-1-2
	else if (x == 5) {
		for (int i = 0; i < 3; i++) {
			cycle(cube[0][i][2], cube[3][2 - i][0], cube[1][i][2], cube[2][i][2]);
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		init();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			char dir, command;
			cin >> dir >> command;

			int idx;
			if (dir == 'U') idx = 0;
			else if (dir == 'D') idx = 1;
			else if (dir == 'F') idx = 2;
			else if (dir == 'B') idx = 3;
			else if (dir == 'L') idx = 4;
			else if (dir == 'R') idx = 5;

			if (command == '+') rotate(idx);
			else if (command == '-') {
				for (int j = 0; j < 3; j++) {
					rotate(idx);
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << "\n";
		}
	}
}