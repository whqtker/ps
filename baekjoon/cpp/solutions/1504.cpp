#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000001

using namespace std;

int n, e;
vector<pair<int, int>> nodes[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(801);

void dijkstra(int s) {
	for (int i = 1;i <= n;i++) {
		dist[i] = INF;
	}
	dist[s] = 0;

	pq.push({ 0,s });
	while (!pq.empty()) {
		int w = pq.top().first;
		int p = pq.top().second;
		pq.pop();

		if (dist[p] < w)
			continue;

		for (int i = 0;i < nodes[p].size();i++) {
			int near = nodes[p][i].second;
			int near_w = nodes[p][i].first;

			if (dist[near] > w + near_w) {
				dist[near] = w + near_w;
				pq.push({ dist[near],near });
			}
		}
	}
}

int main() {
	cin >> n >> e;

	for (int i = 0;i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;

		nodes[a].push_back({ c,b });
		nodes[b].push_back({ c,a });
	}

	int pass1, pass2; // 지나야 하는 노드
	cin >> pass1 >> pass2;


	// start -> pass1 -> pass2 -> n : d1 + d3 + d5
	// start -> pass2 -> pass1 -> n : d2 + d3 + d4
	// pass1 -> pass2가 INF면 무조건 답 없음.
	dijkstra(1);
	int d1 = dist[pass1];
	int d2 = dist[pass2];

	dijkstra(pass1);
	int d3 = dist[pass2];
	int d4 = dist[n];
	if (d3 >= INF) {
		cout << -1;
		return 0;
	}

	dijkstra(pass2);
	int d5 = dist[n];

	int ans = min(d1 + d3 + d5, d2 + d3 + d4);
	if (ans >= INF)
		cout << -1;
	else
		cout << min(d1 + d3 + d5, d2 + d3 + d4);
}