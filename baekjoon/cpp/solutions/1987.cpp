#include <iostream>

using namespace std;

int r, c;
int ans = 0;
char arr[20][20];
int visited[26];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool out_of_bound(int x, int y) {
	return x < 0 || y < 0 || x >= r || y >= c;
}

void dfs(int x, int y, int cnt) {
	bool flag = false;

	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!out_of_bound(nx, ny)) {
			char next = arr[nx][ny];
			if (!visited[next - 'A']) {
				flag = true;
				visited[next - 'A'] = 1;
				dfs(nx, ny, cnt + 1);
				visited[next - 'A'] = 0;
			}
		}
	}

	if (!flag)
		ans = ans < cnt ? cnt : ans;
}

int main() {
	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> arr[i][j];
		}
	}

	visited[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ans;
}