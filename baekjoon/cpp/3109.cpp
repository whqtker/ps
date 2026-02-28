#include <iostream>

using namespace std;

int n, m;
char arr[10001][501];
int visited[10001][501];
int done[10001];
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
int ans;

void dfs(int num, int x, int y) {
	if (y == m - 1 && !done[num]) {
		ans++;
		done[num] = 1;

		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny]) continue;
		if (arr[nx][ny] == 'x') continue;

		if (!done[num]) {
			visited[nx][ny] = 1;
			dfs(num, nx, ny);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		dfs(i, i, 0);
	}

	cout << ans;
}