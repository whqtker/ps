#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, g, r;
int arr[51][51]; // 초록 뿌린 경우 3, 빨강 뿌린 경우 4
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int red_visited[51][51];
int green_visited[51][51];
int flower[51][51];
int ans = 0;
vector<pair<int, int>> cand; // 배양액을 뿌릴 수 있는 땅의 좌표

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			red_visited[i][j] = 0;
			green_visited[i][j] = 0;
			flower[i][j] = 0;
		}
	}
}

void bfs() {
	clear();
	queue<tuple<int, int, int>> q; // { x, y, 색 }, 초록이면 3, 빨강이면 4
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 3) {
				q.push({ i, j, 3 });
				green_visited[i][j] = 1;
			}
			else if (arr[i][j] == 4) {
				q.push({ i, j, 4 });
				red_visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		if (flower[x][y]) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 0) continue;
			if (c == 3 && green_visited[nx][ny]) continue;
			if (c == 4 && red_visited[nx][ny]) continue;
			if (flower[nx][ny]) continue;

			// 다른 색이 방문하고 이동하면 개화하는 경우 flower[nx][ny] = 1
			// 다른 색이 방문하지 않은 경우만 방문처리 및 큐에 삽입
			if (c == 3) {
				if (red_visited[nx][ny] != 0 && red_visited[nx][ny] == green_visited[x][y] + 1) {
					flower[nx][ny] = 1;
				}
				else if (green_visited[nx][ny] == 0 && red_visited[nx][ny] == 0) {
					green_visited[nx][ny] = green_visited[x][y] + 1;
					q.push({ nx, ny, 3 });
				}
			}
			else {
				if (green_visited[nx][ny] != 0 && green_visited[nx][ny] == red_visited[x][y] + 1) {
					flower[nx][ny] = 1;
				}
				else if (red_visited[nx][ny] == 0 && green_visited[nx][ny] == 0) {
					red_visited[nx][ny] = red_visited[x][y] + 1;
					q.push({ nx, ny, 4 });
				}
			}
		}
	}

	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flower[i][j]) {
				cur++;
			}
		}
	}

	ans = max(ans, cur);
}

// 배양액 뿌리기
void dfs(int green, int red, int idx) {
	// 배양액을 모두 뿌린 경우
	if (green == g && red == r) {
		bfs();
		return;
	}

	if (idx == cand.size()) return;

	int x = cand[idx].first;
	int y = cand[idx].second;

	if (green + 1 <= g) {
		arr[x][y] = 3;
		dfs(green + 1, red, idx + 1);
		arr[x][y] = 2;
	}

	if (red + 1 <= r) {
		arr[x][y] = 4;
		dfs(green, red + 1, idx + 1);
		arr[x][y] = 2;
	}

	dfs(green, red, idx + 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				cand.push_back({ i,j });
			}
		}
	}

	dfs(0, 0, 0);

	cout << ans;
}