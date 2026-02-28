#include <iostream>
#include <algorithm>

#define INF 401

using namespace std;

int dist[401][401];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b; // a 다음에 b 발생
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		if (dist[b][a] != INF)
			cout << "1\n";
		else if (dist[a][b] != INF)
			cout << "-1\n";
		else
			cout << "0\n";
	}
}