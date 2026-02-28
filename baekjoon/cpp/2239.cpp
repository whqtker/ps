#include <iostream>
#include <string>

using namespace std;

string arr[9];
int row[9][10]; // row[i][j]: i번 째 행에 j가 있는지
int col[9][10]; // col[i][j]: i번 째 열에 j가 있는지
int mini[3][3][10]; // mini[i][j][k]: (i, j)번 째 3x3 정사각형에 k가 있는지
bool flag = false;

void bt(int x, int y) {
	if (x > 8) {
		for (int i = 0;i < 9;i++) {
			cout << arr[i] << "\n";
		}
		flag = true;
		return;
	}

	if (arr[x][y] != '0') {
		if (y < 8)
			bt(x, y + 1);
		else
			bt(x + 1, 0);
	}

	else {
		for (int i = 1;i <= 9;i++) {
			if (!row[x][i] && !col[y][i] && !mini[x / 3][y / 3][i]) {
				row[x][i] = 1;
				col[y][i] = 1;
				mini[x / 3][y / 3][i] = 1;
				arr[x][y] = i + '0';

				if (y < 8)
					bt(x, y + 1);
				else
					bt(x + 1, 0);

				if (flag)
					return;

				row[x][i] = 0;
				col[y][i] = 0;
				mini[x / 3][y / 3][i] = 0;
				arr[x][y] = '0';
			}
		}
	}
}

int main() {
	for (int i = 0;i < 9;i++) {
		string s;
		cin >> s;
		arr[i] = s;
	}

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (arr[i][j] != '0') {
				row[i][arr[i][j] - '0'] = 1;
				col[j][arr[i][j] - '0'] = 1;
				mini[i / 3][j / 3][arr[i][j] - '0'] = 1;
			}
		}
	}

	bt(0, 0);
}