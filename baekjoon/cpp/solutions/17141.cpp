#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[51][51];
int visited[51][51];
int n, m;
vector<pair<int, int>> v;
vector<int> virus;
int bt_visited[10];
int ans = 2501;
int v_size;

bool outOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
		}
	}
}

void bt(int cur, int cnt) {
	if (cnt == m) {
		clear();
		queue<pair<int, int>> q;
		int time = 0;

		for (int i = 0;i < m;i++) {
			q.push({ v[virus[i]].first,v[virus[i]].second });
			visited[v[virus[i]].first][v[virus[i]].second] = 1;
		}

		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			int t = visited[x][y];
			q.pop();


			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!outOfRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 1) {
					visited[nx][ny] += t + 1;
					time = visited[nx][ny];
					q.push({ nx,ny });
				}
			}
		}

		bool flag = true;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (visited[i][j] == 0 && arr[i][j] != 1)
					flag = false;
			}
		}

		if (flag) {
			if (time == 0)
				ans = time;
			else if (ans > time - 1)
				ans = time - 1;
		}

		return;
	}

	for (int i = cur;i < v_size;i++) {
		if (!bt_visited[i]) {
			bt_visited[i] = 1;
			virus.push_back(i);
			bt(i, cnt + 1);
			virus.pop_back();
			bt_visited[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	v_size = v.size();

	bt(0, 0);
	if (ans == 2501)
		cout << -1;
	else
		cout << ans;
}