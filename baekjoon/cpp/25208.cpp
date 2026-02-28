#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char arr[500][500];
int visited[500][500][6];
int n, m;

bool outOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	queue<tuple<int, int, int>> q; // {탐정x, 탐정y, 뚫린 면 방향(북, 동, 남, 서, 위, 아래)
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') {
				q.push({ i,j,5 });
				visited[i][j][5] = 1;
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int dd[4][6] = { {5,1,4,3,0,2},{0,5,2,4,1,3},{4,1,5,3,2,0},{0,4,2,5,3,1} }; // 이동에 따른 뚫린 면이 향하는 방향

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();

		if (arr[x][y] == 'R') {
			if (d == 5) {
				cout << visited[x][y][d] - 1;
				return 0;
			}
			else
				continue;
		}

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (outOfRange(nx, ny)) continue;

			if (!visited[nx][ny][dd[i][d]] && arr[nx][ny] != '#') {
				visited[nx][ny][dd[i][d]] = visited[x][y][d] + 1;
				q.push({ nx,ny,dd[i][d] });
			}
		}
	}

	cout << -1;
}