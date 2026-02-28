#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

#define INF 1e12

using namespace std;

vector<pair<int, int>> graph[10001];
long long dist[10001][21]; // dist[i][j]: 출발지부터 i까지 j개의 도로를 포장한 경우 최소 비용

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dist[i][j] = INF;
		}
	}

	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq; // 가중치, 노드, 포장한 도로 수
	pq.push({ 0,1,0 });
	dist[1][0] = 0;

	while (!pq.empty()) {
		long long w = get<0>(pq.top());
		int node = get<1>(pq.top());
		int cnt = get<2>(pq.top());
		pq.pop();

		if (dist[node][cnt] < w) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int nnode = graph[node][i].first;
			int nw = graph[node][i].second;

			// 도로를 포장할 수 있다면
			if (cnt < k && dist[nnode][cnt + 1] > w) {
				dist[nnode][cnt + 1] = w;
				pq.push({ dist[nnode][cnt + 1],nnode,cnt + 1 });
			}

			// 그냥 가는 경우
			if (dist[nnode][cnt] > w + nw) {
				dist[nnode][cnt] = w + nw;
				pq.push({ dist[nnode][cnt],nnode,cnt });
			}
		}
	}

	long long ans = INF;
	for (int i = 0; i <= k; i++) {
		ans = min(ans, dist[n][i]);
	}
	cout << ans;
}