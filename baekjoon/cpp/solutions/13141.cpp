#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define INF 1e9

using namespace std;

vector<int> graph[201][201]; // graph[i][j] = {l1, l2, ...} : (i, j) 간선의 길이는 l1, l2, ...
int dist[201][201];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b].push_back(c);
		graph[b][a].push_back(c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else if (graph[i][j].size() != 0) {
				int minLength = *min_element(graph[i][j].begin(), graph[i][j].end());
				dist[i][j] = minLength;
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	// 각 노드 간 최단 거리를 구한다.
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 모든 간선에 대해 다 타기까지의 시간을 구한다.
	// 시작점을 S라고 할 때, 길이 L의 간선 (i, j)가 다 타는 시간은 (dist[S][i] + dist[S][j] + L) / 2
	double ans = 2e9;
	for (int start = 1; start <= n; start++) {
		double tmp = 0.0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int idx = 0; idx < graph[i][j].size(); idx++) {
					int L = graph[i][j][idx];
					tmp = max(tmp, (double)(dist[start][i] + dist[start][j] + L) / 2.0);
				}
			}
		}

		ans = min(ans, tmp);
	}

	cout << fixed;
	cout << setprecision(1);
	cout << ans;
}