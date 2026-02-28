#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	vector<vector<int>> visited(n, vector<int>(n));
	int k = 0; // ¼¶ÀÇ ¹øÈ£
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j] && v[i][j] == 1) {
				k++;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				v[i][j] = k;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					if (x - 1 >= 0 && v[x - 1][y] == 1 && !visited[x - 1][y]) {
						v[x - 1][y] = k;
						q.push({ x - 1,y });
						visited[x - 1][y] = 1;
					}
					if (x + 1 < n && v[x + 1][y] == 1 && !visited[x + 1][y]) {
						v[x + 1][y] = k;
						q.push({ x + 1,y });
						visited[x + 1][y] = 1;
					}
					if (y - 1 >= 0 && v[x][y - 1] == 1 && !visited[x][y - 1]) {
						v[x][y - 1] = k;
						q.push({ x ,y - 1 });
						visited[x][y - 1] = 1;
					}
					if (y + 1 < n && v[x][y + 1] == 1 && !visited[x][y + 1]) {
						v[x][y + 1] = k;
						q.push({ x ,y + 1 });
						visited[x][y + 1] = 1;
					}

					q.pop();
				}
			}
		}
	}

	int min = 10001;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] != 0) {
				vector<vector<int>> visited2(n, vector<int>(n));
				int num = v[i][j];
				queue<pair<int, int>> q;
				q.push({ i,j });

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					if (x - 1 >= 0) {
						if (v[x - 1][y] == 0 && !visited2[x - 1][y]) {
							q.push({ x - 1,y });
							visited2[x - 1][y] = visited2[x][y] + 1;
						}
						else if (v[x - 1][y] != 0 && v[x - 1][y] != num)
							min = min > visited2[x][y] ? visited2[x][y] : min;
					}
					if (x + 1 < n) {
						if (v[x + 1][y] == 0 && !visited2[x + 1][y]) {
							q.push({ x + 1,y });
							visited2[x + 1][y] = visited2[x][y] + 1;
						}
						else if (v[x + 1][y] != 0 && v[x + 1][y] != num)
							min = min > visited2[x][y] ? visited2[x][y] : min;
					}
					if (y - 1 >= 0) {
						if (v[x][y - 1] == 0 && !visited2[x][y - 1]) {
							q.push({ x,y - 1 });
							visited2[x][y - 1] = visited2[x][y] + 1;
						}
						else if (v[x][y - 1] != 0 && v[x][y - 1] != num)
							min = min > visited2[x][y] ? visited2[x][y] : min;
					}
					if (y + 1 < n) {
						if (v[x][y + 1] == 0 && !visited2[x][y + 1]) {
							q.push({ x,y + 1 });
							visited2[x][y + 1] = visited2[x][y] + 1;
						}
						else if (v[x][y + 1] != 0 && v[x][y + 1] != num)
							min = min > visited2[x][y] ? visited2[x][y] : min;
					}

					q.pop();
				}
			}
		}
	}

	cout << min;
}