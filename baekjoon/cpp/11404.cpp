#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10000001

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(n + 1));
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (v[a][b] == 0)
			v[a][b] = c;
		else
			v[a][b] = min(v[a][b], c);
	}

	vector<vector<int>> dist(n + 1, vector<int>(n + 1)); // 최단거리 저장
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (i == j)
				dist[i][j] = 0;
			else if (v[i][j] != 0)
				dist[i][j] = v[i][j];
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (dist[i][j] == INF)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}