#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool outOfBound(int x, int y, int n, int m) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return true;
	else
		return false;
}

void bfs(vector<string> v, int n, int m) {
	vector<vector<int>> visited(n, vector<int>(m, 0));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		if (!outOfBound(x + 1, y, n, m) && visited[x + 1][y] == 0 && v[x + 1][y] == '1') {
			q.push({ x + 1,y });
			visited[x + 1][y] = visited[x][y] + 1;
		}
		if (!outOfBound(x - 1, y, n, m) && visited[x - 1][y] == 0 && v[x - 1][y] == '1') {
			q.push({ x - 1,y });
			visited[x - 1][y] = visited[x][y] + 1;
		}
		if (!outOfBound(x, y + 1, n, m) && visited[x][y + 1] == 0 && v[x][y + 1] == '1') {
			q.push({ x ,y + 1 });
			visited[x][y + 1] = visited[x][y] + 1;
		}
		if (!outOfBound(x, y - 1, n, m) && visited[x][y - 1] == 0 && v[x][y - 1] == '1') {
			q.push({ x ,y - 1 });
			visited[x][y - 1] = visited[x][y] + 1;
		}
		q.pop();
	}

	cout << visited[n - 1][m - 1];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	bfs(v, n, m);
}