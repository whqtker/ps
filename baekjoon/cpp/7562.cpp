#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

void bfs() {
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;

	queue<pair<int, int>> q;
	q.push({ sx,sy });
	v[sx][sy] = 0;

	if (sx == ex && sy == ey)
		cout << 0 << "\n";
	else {
		int ans = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			if (x - 2 >= 0 && y + 1 < n && v[x - 2][y + 1] == 0) {
				q.push({ x - 2,y + 1 });
				v[x - 2][y + 1] = v[x][y] + 1;

				if (x - 2 == ex && y + 1 == ey) {
					ans = v[x - 2][y + 1];
					break;
				}
			}
			if (x - 1 >= 0 && y + 2 < n && v[x - 1][y + 2] == 0) {
				q.push({ x - 1,y + 2 });
				v[x - 1][y + 2] = v[x][y] + 1;

				if (x - 1 == ex && y + 2 == ey) {
					ans = v[x - 1][y + 2];
					break;
				}
			}
			if (x + 1 < n && y + 2 < n && v[x + 1][y + 2] == 0) {
				q.push({ x + 1,y + 2 });
				v[x + 1][y + 2] = v[x][y] + 1;

				if (x + 1 == ex && y + 2 == ey) {
					ans = v[x + 1][y + 2];
					break;
				}
			}
			if (x + 2 < n && y + 1 < n && v[x + 2][y + 1] == 0) {
				q.push({ x + 2,y + 1 });
				v[x + 2][y + 1] = v[x][y] + 1;

				if (x + 2 == ex && y + 1 == ey) {
					ans = v[x + 2][y + 1];
					break;
				}
			}
			if (x + 2 < n && y - 1 >= 0 && v[x + 2][y - 1] == 0) {
				q.push({ x + 2,y - 1 });
				v[x + 2][y - 1] = v[x][y] + 1;

				if (x + 2 == ex && y - 1 == ey) {
					ans = v[x + 2][y - 1];
					break;
				}
			}
			if (x + 1 < n && y - 2 >= 0 && v[x + 1][y - 2] == 0) {
				q.push({ x + 1,y - 2 });
				v[x + 1][y - 2] = v[x][y] + 1;

				if (x + 1 == ex && y - 2 == ey) {
					ans = v[x + 1][y - 2];
					break;
				}
			}
			if (x - 1 >= 0 && y - 2 >= 0 && v[x - 1][y - 2] == 0) {
				q.push({ x - 1,y - 2 });
				v[x - 1][y - 2] = v[x][y] + 1;

				if (x - 1 == ex && y - 2 == ey) {
					ans = v[x - 1][y - 2];
					break;
				}
			}
			if (x - 2 >= 0 && y - 1 >= 0 && v[x - 2][y - 1] == 0) {
				q.push({ x - 2,y - 1 });
				v[x - 2][y - 1] = v[x][y] + 1;

				if (x - 2 == ex && y - 1 == ey) {
					ans = v[x - 2][y - 1];
					break;
				}
			}

			q.pop();
		}

		cout << ans << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		bfs();
	}
}