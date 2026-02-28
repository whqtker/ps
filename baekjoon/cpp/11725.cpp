#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<vector<int>> v(n + 1);
	for (int i = 0;i < n - 1;i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	queue<int> q;
	q.push(1);

	vector<int> visited(n + 1);
	vector<int> par(n + 1);
	visited[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int j = 0;j < v[x].size();j++) {
			int tmp = v[x][j];
			if (!visited[tmp]) {
				q.push(tmp);
				par[tmp] = x;
				visited[tmp] = x;
			}
		}
	}

	for (int i = 2;i <= n;i++) {
		cout << par[i] << "\n";
	}
}