#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	int k, w, h;
	cin >> k >> w >> h;

	vector<vector<int>> v(h, vector<int>(w));
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });

	vector<vector<vector<int>>> visited(h, vector<vector<int>>(w, vector<int>(k + 1)));

	int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
	int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int m = get<2>(q.front());
		q.pop();

		// 말처럼 이동할 수 있는 경우
		if (m < k) {
			for (int i = 0;i < 8;i++) {
				int _x = x + dx[i];
				int _y = y + dy[i];
				if (_x >= 0 && _x < h && _y >= 0 && _y < w && !visited[_x][_y][m + 1] && v[_x][_y] == 0) {
					q.push({ _x,_y,m + 1 });
					visited[_x][_y][m + 1] = visited[x][y][m] + 1;
				}
			}
		}

		if (x - 1 >= 0 && !visited[x - 1][y][m] && v[x - 1][y] == 0) {
			q.push({ x - 1,y,m });
			visited[x - 1][y][m] = visited[x][y][m] + 1;
		}
		if (x + 1 < h && !visited[x + 1][y][m] && v[x + 1][y] == 0) {
			q.push({ x + 1,y,m });
			visited[x + 1][y][m] = visited[x][y][m] + 1;
		}
		if (y - 1 >= 0 && !visited[x][y - 1][m] && v[x][y - 1] == 0) {
			q.push({ x ,y - 1,m });
			visited[x][y - 1][m] = visited[x][y][m] + 1;
		}
		if (y + 1 < w && !visited[x][y + 1][m] && v[x][y + 1] == 0) {
			q.push({ x ,y + 1,m });
			visited[x][y + 1][m] = visited[x][y][m] + 1;
		}
	}

	if (w == 1 && h == 1)
		cout << 0;
	else {
		int ans = 40001;
		for (int i = 0;i <= k;i++) {
			if (visited[h - 1][w - 1][i] != 0 && ans > visited[h - 1][w - 1][i])
				ans = visited[h - 1][w - 1][i];
		}

		if (ans == 40001)
			cout << -1;
		else
			cout << ans;
	}
}