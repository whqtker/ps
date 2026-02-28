#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> visited;

// 'ㅜ'자 모양 제외
int dfs(int i, int j, int cnt, int sum) {
	if (cnt == 4) {
		return sum;
	}

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	int ret = 0;
	for (int k = 0;k < 4;k++) {
		int x = i + dx[k];
		int y = j + dy[k];

		if (x >= 0 && y >= 0 && x < n && y < m && cnt < 4) {
			if (!visited[x][y]) {
				visited[x][y] = 1;
				ret = ret < dfs(x, y, cnt + 1, sum + v[x][y]) ? dfs(x, y, cnt + 1, sum + v[x][y]) : ret;
				visited[x][y] = 0;
			}
		}
	}
	return ret;
}

int wu(int i, int j) {
	int max = 0;
	if (j - 1 >= 0 && j + 1 < m && i - 1 >= 0) {
		max = v[i][j] + v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1] > max ? v[i][j] + v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1] : max;
	}
	if (j - 1 >= 0 && j + 1 < m && i + 1 < n) {
		max = v[i][j] + v[i + 1][j - 1] + v[i + 1][j] + v[i + 1][j + 1] > max ? v[i][j] + v[i + 1][j - 1] + v[i + 1][j] + v[i + 1][j + 1] : max;
	}
	if (j + 1 < m && i - 1 >= 0 && i + 1 < n) {
		max = v[i][j] + v[i][j + 1] + v[i - 1][j + 1] + v[i + 1][j + 1] > max ? v[i][j] + v[i][j + 1] + v[i - 1][j + 1] + v[i + 1][j + 1] : max;
	}
	if (j - 1 >= 0 && i - 1 >= 0 && i + 1 < n) {
		max = v[i][j] + v[i][j - 1] + v[i - 1][j - 1] + v[i + 1][j - 1] > max ? v[i][j] + v[i][j - 1] + v[i - 1][j - 1] + v[i + 1][j - 1] : max;
	}
	return max;
}

int main() {
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> v[i][j];
		}
	}

	int max = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			visited[i][j] = 1;
			max = dfs(i, j, 1, v[i][j]) > max ? dfs(i, j, 1, v[i][j]) : max;
			max = wu(i, j) > max ? wu(i, j) : max;
			visited[i][j] = 0;
		}
	}
	cout << max;
}