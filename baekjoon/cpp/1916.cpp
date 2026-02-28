#include <iostream>
#include <queue>
#include <vector>

#define INF 100000001

using namespace std;

vector<pair<int, int>> nodes[1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		nodes[s].push_back({ w,e });
	}

	int from, to;
	cin >> from >> to;

	vector<int> dist(n + 1);
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[from] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,from });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < weight)
			continue;

		for (int i = 0; i < nodes[cur].size(); i++) {
			if (dist[nodes[cur][i].second] > weight + nodes[cur][i].first) {
				dist[nodes[cur][i].second] = weight + nodes[cur][i].first;
				pq.push({ dist[nodes[cur][i].second],nodes[cur][i].second });
			}
		}
	}

	cout << dist[to];
}