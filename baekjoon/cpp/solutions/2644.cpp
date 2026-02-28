#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	int m;
	cin >> m;

	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	queue<int> q;
	q.push(x);
	vector<int> visited(n + 1);

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 1;i <= n;i++) {
			if ((v[cur][i] || v[i][cur]) && visited[i] == 0) {
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}
		q.pop();
	}

	if (visited[y] == 0)
		cout << -1;
	else
		cout << visited[y];
}