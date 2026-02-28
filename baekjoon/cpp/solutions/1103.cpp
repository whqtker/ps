#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
bool cycleFlag = false;
int n, m;
int board[50][50];
int visited[50][50];
int cnt[50][50];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OutofBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

void dfs(int x, int y) {
	if (cycleFlag)
		return;

	ans = max(ans, cnt[x][y]);
	int num = board[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * num;
		int ny = y + dy[i] * num;

		if (!OutofBound(nx, ny) && board[nx][ny] && cnt[x][y] + 1 > cnt[nx][ny]) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				cnt[nx][ny] = cnt[x][y] + 1;
				dfs(nx, ny);
				visited[nx][ny] = 0;
			}
			else {
				cycleFlag = true;
				ans = -1;
				return;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;

			if (c == 'H')
				board[i][j] = 0;
			else
				board[i][j] = c - '0';
		}
	}

	cnt[0][0] = 1;
	visited[0][0] = 1;
	dfs(0, 0);

	cout << ans;
}