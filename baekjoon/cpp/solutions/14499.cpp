#include <iostream>

using namespace std;

int board[21][21];
int dice[6]; // 상, 하, 좌, 우, 앞, 뒤

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 동, 서, 북, 남
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		x += dx[dir - 1];
		y += dy[dir - 1];

		// 범위를 벗어난 경우
		if (x < 0 || y < 0 || x >= n || y >= m) {
			x -= dx[dir - 1];
			y -= dy[dir - 1];
		}
		else {
			// 동쪽 이동: 앞, 뒤 그대로
			if (dir == 1) {
				int tmp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[0];
				dice[0] = dice[2];
				dice[2] = tmp;
			}
			// 서쪽 이동: 앞, 뒤 그대로
			else if (dir == 2) {
				int tmp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[0];
				dice[0] = dice[3];
				dice[3] = tmp;
			}
			// 북쪽 이동: 동, 서 그대로
			else if (dir == 3) {
				int tmp = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[0];
				dice[0] = dice[5];
				dice[5] = tmp;
			}
			// 남쪽 이동: 동, 서 그대로
			else if (dir == 4) {
				int tmp = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[0];
				dice[0] = dice[4];
				dice[4] = tmp;
			}
			// 보드가 0인 경우
			if (board[x][y] == 0) {
				board[x][y] = dice[1];
				cout << dice[0] << "\n";
			}
			else {
				dice[1] = board[x][y];
				board[x][y] = 0;
				cout << dice[0] << "\n";
			}
		}
	}
}