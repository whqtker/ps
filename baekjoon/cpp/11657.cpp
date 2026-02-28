#include <iostream>
#include <algorithm>

#define MAX_INF 6e7+1

using namespace std;

int arr[501][501];
int dist[501][501];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = MAX_INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		arr[s][e] = min(arr[s][e], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = min(dist[i][j], 0);
			else if (arr[i][j])
				dist[i][j] = arr[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == MAX_INF || dist[k][j] == MAX_INF)
					continue;

				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// i에서 음의 사이클이 발생하고 1에서 도달할 수 있는 경우
	for (int i = 1; i <= n; i++) {
		if (dist[i][i] < 0) {
			if (dist[1][i] != MAX_INF) {
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[1][i] == MAX_INF) {
			cout << -1 << "\n";
		}
		else
			cout << dist[1][i] << "\n";
	}
}