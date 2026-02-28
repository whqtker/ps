#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

char board[51][51];
int visited[51][51][(1 << 6)];
int n, m;

bool OutofBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int main() {
	cin >> n >> m;

	int sx, sy; // 시작 좌표
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == '0') {
				sx = i;
				sy = j;
			}
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ sx,sy,0 });
	visited[sx][sy][0] = 1;

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int ans = -1;
	while (!q.empty()) {
		int x, y, keys;
		tie(x, y, keys) = q.front();
		int cnt = visited[x][y][keys];
		q.pop();

		if (board[x][y] == '1') {
			ans = cnt - 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 방문하지 않았고 벽이 아닌 경우
			if (!OutofBound(nx, ny) && board[nx][ny] != '#' && !visited[nx][ny][keys]) {
				// 빈 칸이거나 출발지거나 도착지
				if (board[nx][ny] == '.' || board[nx][ny] == '0' || board[nx][ny] == '1') {
					visited[nx][ny][keys] = cnt + 1;
					q.push({ nx,ny,keys });
				}
				// 열쇠
				else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f') {
					int key_number = board[nx][ny] - 'a';

					int newKeys = keys | (1 << key_number);
					if (!visited[nx][ny][newKeys]) {
						visited[nx][ny][newKeys] = cnt + 1;
						q.push({ nx,ny,newKeys });
					}
				}
				// 문
				else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F') {
					char door = board[nx][ny];
					char key = tolower(door);
					int key_number = key - 'a';

					// 열쇠를 가지고 있다면
					if (keys & (1 << key_number)) {
						visited[nx][ny][keys] = cnt + 1;
						q.push({ nx,ny,keys });
					}
				}
			}
		}
	}

	cout << ans;
}