#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> v(m, vector<int>(n)); // 직사각형이 있는 구역 or 방문한 구역은 1
	for (int i = 0;i < k;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1;j < x2;j++) {
			for (int l = y1;l < y2;l++) {
				v[l][j] = 1;
			}
		}
	}

	queue<pair<int, int>> q;
	vector<int> s;
	int cnt = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] == 0) {
				cnt++;
				q.push({ i,j });
				v[i][j] = 1;
				int tmp = 1; // 넓이

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					if (x - 1 >= 0 && v[x - 1][y] == 0) {
						q.push({ x - 1,y });
						v[x - 1][y] = 1;
						tmp++;
					}
					if (x + 1 < m && v[x + 1][y] == 0) {
						q.push({ x + 1,y });
						v[x + 1][y] = 1;
						tmp++;
					}
					if (y - 1 >= 0 && v[x][y - 1] == 0) {
						q.push({ x,y - 1 });
						v[x][y - 1] = 1;
						tmp++;
					}
					if (y + 1 < n && v[x][y + 1] == 0) {
						q.push({ x,y + 1 });
						v[x][y + 1] = 1;
						tmp++;
					}
					q.pop();
				}
				s.push_back(tmp);
			}
		}
	}

	cout << cnt << "\n";
	sort(s.begin(), s.end());
	for (int i = 0;i < s.size();i++) {
		cout << s[i] << " ";
	}
}