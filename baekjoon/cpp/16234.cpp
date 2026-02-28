#include <iostream>
#include <cmath>

using namespace std;

int graph[51][51];
int visited[51][51];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, l, r;
int cnt = 0;
int sum = 0;

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

void dfs(int x, int y, int counter) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		int diff = abs(graph[x][y] - graph[nx][ny]);

		if (!visited[nx][ny] && l<=diff&&diff<=r) {
			visited[nx][ny] = counter;
			sum += graph[nx][ny];
			cnt++;
			dfs(nx, ny, counter);
		}
	}
}

void arrange(int counter, int cnt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == counter) {
				graph[i][j] = sum / cnt;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int day = 0;
	while (1) {
		clear();

		bool flag = false;
		int counter = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					cnt = 1;
					sum = graph[i][j];
					visited[i][j] = counter;

					dfs(i, j, counter);

					if (cnt > 1) {
						arrange(counter, cnt);
						flag = true;
					}

					counter++;
				}
			}
		}

		if (!flag) break;

		day++;
	}

	cout << day;
}