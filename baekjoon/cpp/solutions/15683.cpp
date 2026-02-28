#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans = 65; // 사각지대의 최소 크기
int board[8][8];
vector<pair<int, int>> cctv; // cctv의 좌표

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OutofBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

void cal(int x, int y, int d) {
	d %= 4;

	while (1) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		x = nx;
		y = ny;

		if (OutofBound(nx, ny))
			return;

		if (board[nx][ny] == 6)
			return;

		if (board[nx][ny])
			continue;

		board[nx][ny] = -1;

	}
}

void dfs(int k) {
	// 모든 cctv에 접근한 경우
	if (k == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!board[i][j])
					cnt++;
			}
		}

		ans = min(ans, cnt);
		return;
	}

	int x = cctv[k].first;
	int y = cctv[k].second;

	int tmp[8][8];
	// 0: 북, 1: 동, 2: 남, 3: 서
	for (int d = 0; d < 4; d++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		if (board[x][y] == 1) {
			cal(x, y, d);
		}
		else if (board[x][y] == 2) {
			cal(x, y, d);
			cal(x, y, d + 2);
		}
		else if (board[x][y] == 3) {
			cal(x, y, d);
			cal(x, y, d + 1);
		}
		else if (board[x][y] == 4) {
			cal(x, y, d);
			cal(x, y, d + 1);
			cal(x, y, d + 2);
		}
		else if (board[x][y] == 5) {
			cal(x, y, d);
			cal(x, y, d + 1);
			cal(x, y, d + 2);
			cal(x, y, d + 3);
		}

		dfs(k + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] > 0 && board[i][j] < 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0);
	cout << ans;
}