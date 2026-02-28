#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> board;
int visited[1000][1000]; // 1: 방문, -1: 방문 완료
int cnt = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	
	char cur = board[x][y];
	if (cur == 'U') {
		int nx = x - 1;
		int ny = y;

		if (visited[nx][ny] == 0)
			dfs(nx, ny);
		else if (visited[nx][ny] == 1)
			cnt++;
	}
	else if (cur == 'D') {
		int nx = x + 1;
		int ny = y;

		if (visited[nx][ny] == 0)
			dfs(nx, ny);
		else if (visited[nx][ny] == 1)
			cnt++;
	}
	else if (cur == 'L') {
		int nx = x;
		int ny = y - 1;

		if (visited[nx][ny] == 0)
			dfs(nx, ny);
		else if (visited[nx][ny] == 1)
			cnt++;
	}
	else if (cur == 'R') {
		int nx = x;
		int ny = y + 1;

		if (visited[nx][ny] == 0)
			dfs(nx, ny);
		else if (visited[nx][ny] == 1)
			cnt++;
	}

	visited[x][y] = -1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
			}
		}
	}

	cout << cnt;
}