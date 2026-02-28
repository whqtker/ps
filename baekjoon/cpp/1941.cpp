#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char board[5][5];
int visited[5][5];
int som, yeon;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans;

bool oufOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= 5 || y >= 5;
}

void dfs(int X, int Y, int k) {
	if (k == 7) {
		// 가로, 세로로 인접한지 BFS로 확인
		if (som >= 4) {
			vector<vector<int>> bfsvisited(5, vector<int>(5));
			queue<pair<int, int>> q;
			q.push({ X,Y });
			bfsvisited[X][Y] = 1;
			int cnt = 1;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0;i < 4;i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (!oufOfBound(nx, ny) && !bfsvisited[nx][ny] && visited[nx][ny]) {
						bfsvisited[nx][ny] = 1;
						cnt++;
						q.push({ nx,ny });
					}
				}
			}

			if (cnt == 7) {
				ans++;
			}
		}

		return;
	}

	for (int i = X;i < 5;i++) {
		for (int j = (i == X ? Y : 0);j < 5;j++) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				if (board[i][j] == 'S')
					som++;
				else
					yeon++;

				dfs(i, j, k + 1);

				visited[i][j] = 0;
				if (board[i][j] == 'S')
					som--;
				else
					yeon--;
			}
		}
	}
}

int main() {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0);
	cout << ans;
}