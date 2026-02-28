#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int w, h;
		cin >> w >> h;

		vector<vector<char>> v(h, vector<char>(w));
		queue<pair<int, int>> q, f; // 상근이, 불
		vector<vector<int>> time(h, vector<int>(w));
		vector<vector<int>> fireTime(h, vector<int>(w));

		for (int j = 0;j < h;j++) {
			for (int k = 0;k < w;k++) {
				char c;
				cin >> c;
				v[j][k] = c;

				if (c == '@') {
					q.push({ j,k });
					time[j][k] = 1;
				}
				else if (c == '*') {
					f.push({ j,k });
					fireTime[j][k] = 1;
				}
			}
		}

		while (!f.empty()) {
			int x = f.front().first;
			int y = f.front().second;

			if (x - 1 >= 0 && fireTime[x - 1][y] == 0 && (v[x - 1][y] == '.' || v[x - 1][y] == '@')) {
				f.push({ x - 1,y });
				fireTime[x - 1][y] = fireTime[x][y] + 1;
			}
			if (x + 1 < h && fireTime[x + 1][y] == 0 && (v[x + 1][y] == '.' || v[x + 1][y] == '@')) {
				f.push({ x + 1,y });
				fireTime[x + 1][y] = fireTime[x][y] + 1;
			}
			if (y - 1 >= 0 && fireTime[x][y - 1] == 0 && (v[x][y - 1] == '.' || v[x][y - 1] == '@')) {
				f.push({ x ,y - 1 });
				fireTime[x][y - 1] = fireTime[x][y] + 1;
			}
			if (y + 1 < w && fireTime[x][y + 1] == 0 && (v[x][y + 1] == '.' || v[x][y + 1] == '@')) {
				f.push({ x ,y + 1 });
				fireTime[x][y + 1] = fireTime[x][y] + 1;
			}
			f.pop();
		}

		int fast = 1000001;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
				fast = fast > time[x][y] ? time[x][y] : fast;
			}

			if (x - 1 >= 0 && time[x - 1][y] == 0 && v[x - 1][y] == '.') {
				if (fireTime[x - 1][y] == 0 || time[x][y] + 1 < fireTime[x - 1][y]) {
					q.push({ x - 1,y });
					time[x - 1][y] = time[x][y] + 1;
				}
			}
			if (x + 1 < h && time[x + 1][y] == 0 && v[x + 1][y] == '.') {
				if (fireTime[x + 1][y] == 0 || time[x][y] + 1 < fireTime[x + 1][y]) {
					q.push({ x + 1,y });
					time[x + 1][y] = time[x][y] + 1;
				}
			}
			if (y - 1 >= 0 && time[x][y - 1] == 0 && v[x][y - 1] == '.') {
				if (fireTime[x][y - 1] == 0 || time[x][y] + 1 < fireTime[x][y - 1]) {
					q.push({ x ,y - 1 });
					time[x][y - 1] = time[x][y] + 1;
				}
			}
			if (y + 1 < w && time[x][y + 1] == 0 && v[x][y + 1] == '.') {
				if (fireTime[x][y + 1] == 0 || time[x][y] + 1 < fireTime[x][y + 1]) {
					q.push({ x ,y + 1 });
					time[x][y + 1] = time[x][y] + 1;
				}
			}
			q.pop();
		}

		if (fast == 1000001)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << fast << "\n";
	}
}