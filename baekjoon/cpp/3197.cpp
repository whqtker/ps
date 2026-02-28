#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int r, c;
char board[1501][1501];
int swanVisited[1501][1501]; // swanVisited[x][y] = d: 백조가 (x, y)에 도달할 수 있는 날은 최소 d일 후
int waterVisited[1501][1501]; // waterVisited[x][y] = d: (x, y)는 d일이 되면 물이 된다.
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OutofBound(int x, int y) {
	return x < 0 || y < 0 || x >= r || y >= c;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> r >> c;

	int sx, sy; // 백조 좌표, 하나만 있어도 됨
	queue<pair<int, int>> water;
	queue<tuple<int, int, int>> swan; // {x, y, 현재 탐색에서 만나기까지 최소 날짜}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			waterVisited[i][j] = -1;
			swanVisited[i][j] = -1;

			if (board[i][j] == 'L') {
				sx = i;
				sy = j;
				water.push({ i,j }); // 백조도 물에 있음
				waterVisited[i][j]++;
				swanVisited[i][j] = 0;
			}
			else if (board[i][j] == '.') {
				water.push({ i,j });
				waterVisited[i][j]++;
			}
		}
	}

	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!OutofBound(nx, ny) && waterVisited[nx][ny] == -1) {
				waterVisited[nx][ny] = waterVisited[x][y] + 1;
				water.push({ nx,ny });
			}
		}
	}

	int ans = 2250001;
	swan.push({ sx,sy,0 });
	while (!swan.empty()) {
		int x, y, day;
		tie(x, y, day) = swan.front();
		swan.pop();

		// 백조가 만나면
		if (!(x == sx && y == sy) && board[x][y] == 'L') {
			ans = min(ans, day);
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!OutofBound(nx, ny)) {
				// 방문하지 않았다면
				if (swanVisited[nx][ny] == -1) {

				}
				// 방문했다면
				else if () {

				}
			}

		}

		cout << ans;
	}
}