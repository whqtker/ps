#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, vector<vector<int>>& v) {
	int max = 0;
	for (int k = 0;k <= 100;k++) {
		int cnt = 0;
		vector<vector<int>> visited(n, vector<int>(n));
		queue<pair<int, int>> q;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (visited[i][j] == 0 && v[i][j] > k) {
					q.push({ i,j });
					visited[i][j] = 1;
					cnt++;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;

						if (x - 1 >= 0 && visited[x - 1][y] == 0 && v[x - 1][y] > k) {
							visited[x - 1][y] = 1;
							q.push({ x - 1,y });
						}
						if (x + 1 < n && visited[x + 1][y] == 0 && v[x + 1][y] > k) {
							visited[x + 1][y] = 1;
							q.push({ x + 1,y });
						}
						if (y - 1 >= 0 && visited[x][y - 1] == 0 && v[x][y - 1] > k) {
							visited[x][y - 1] = 1;
							q.push({ x,y - 1 });
						}
						if (y + 1 < n && visited[x][y + 1] == 0 && v[x][y + 1] > k) {
							visited[x][y + 1] = 1;
							q.push({ x,y + 1 });
						}
						q.pop();
					}

				}
			}
		}

		max = cnt > max ? cnt : max;
	}

	cout << max;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	bfs(n, v);
}