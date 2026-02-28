#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	int time = 0;
	while (1) {
		bool flag = false;
		vector<vector<int>> glacier(n, vector<int>(m));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (v[i][j] != 0) {
					glacier[i][j] = 1;
					flag = true;
				}
			}
		}

		if (!flag) {
			cout << 0;
			return 0;
		}

		vector<vector<int>> visited(n, vector<int>(m));
		queue<pair<int, int>> q;
		int cnt = 0;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (!visited[i][j] && glacier[i][j] == 1) {
					cnt++;
					q.push({ i,j });
					visited[i][j] = 1;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;

						if (x - 1 >= 0 && v[x - 1][y] > 0 && !visited[x - 1][y]) {
							visited[x - 1][y] = 1;
							q.push({ x - 1,y });
						}
						if (x + 1 < n && v[x + 1][y] > 0 && !visited[x + 1][y]) {
							visited[x + 1][y] = 1;
							q.push({ x + 1,y });
						}
						if (y - 1 >= 0 && v[x][y - 1] > 0 && !visited[x][y - 1]) {
							visited[x][y - 1] = 1;
							q.push({ x ,y - 1 });
						}
						if (y + 1 < m && v[x][y + 1] > 0 && !visited[x][y + 1]) {
							visited[x][y + 1] = 1;
							q.push({ x ,y + 1 });
						}

						q.pop();
					}
				}
			}
		}

		if (cnt >= 2)
			break;

		time++;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (v[i][j] != 0) {
					if (i - 1 >= 0 && v[i - 1][j] == 0 && glacier[i - 1][j] == 0)
						v[i][j]--;
					if (i + 1 < n && v[i + 1][j] == 0 && glacier[i + 1][j] == 0)
						v[i][j]--;
					if (j - 1 >= 0 && v[i][j - 1] == 0 && glacier[i][j - 1] == 0)
						v[i][j]--;
					if (j + 1 < m && v[i][j + 1] == 0 && glacier[i][j + 1] == 0)
						v[i][j]--;

					if (v[i][j] < 0)
						v[i][j] = 0;
				}
			}
		}
	}

	cout << time;
}