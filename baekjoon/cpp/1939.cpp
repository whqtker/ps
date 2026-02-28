#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> graph[10001];
int dist[10001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}

	int s, e;
	cin >> s >> e;

	priority_queue<pair<int, int>> pq;
	dist[s] = 1e9 + 1;
	pq.push({ 1e9 + 1,s });

	while (!pq.empty()) {
		int w = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (w < dist[node]) continue;
		if (node == e) break;

		for (int i = 0; i < graph[node].size(); i++) {
			int nnode = graph[node][i].second;
			int nw = min(w, graph[node][i].first);

			if (nw > dist[nnode]) {
				dist[nnode] = nw;
				pq.push({ nw,nnode });
			}
		}
	}

	cout << dist[e];
}