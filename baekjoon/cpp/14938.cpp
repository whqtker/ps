#include <iostream>
#include <algorithm>

#define INF 1501;

using namespace std;

int items[101];
int arr[101][101];
int dist[101][101];

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 1;
			}
			else if (arr[i][j]) {
				dist[i][j] = arr[i][j];
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				tmp += items[j];
			}
		}
		cnt = max(cnt, tmp);
	}

	cout << cnt;
}