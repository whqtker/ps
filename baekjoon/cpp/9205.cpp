#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;

		vector<pair<int, int>> v;

		int sx, sy;
		cin >> sx >> sy;
		v.push_back({ sx,sy });

		for (int j = 0;j < n;j++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}

		int ex, ey;
		cin >> ex >> ey;
		v.push_back({ ex,ey });

		vector<vector<int>> graph(n + 2, vector<int>(n + 2));
		for (int j = 0;j < n + 2;j++) {
			for (int k = j;k < n + 2;k++) {
				int x1 = v[j].first;
				int y1 = v[j].second;
				int x2 = v[k].first;
				int y2 = v[k].second;

				if (abs(x1 - x2) + abs(y1 - y2) <= 1000) {
					graph[j][k] = 1;
					graph[k][j] = 1;
				}
			}
		}

		queue<int> q;
		q.push(0);
		vector<int> visited(n + 2);
		visited[0] = 1;

		bool flag = false;
		while (!q.empty()) {
			int idx = q.front();
			int x = v[idx].first;
			int y = v[idx].second;

			if (x == ex && y == ey) {
				cout << "happy\n";
				flag = true;
				break;
			}

			for (int j = 0;j < n + 2;j++) {
				if (graph[idx][j] == 1) {
					if (!visited[j]) {
						q.push(j);
						visited[j] = 1;
					}
				}
			}

			q.pop();
		}

		if (!flag)
			cout << "sad\n";
	}
}