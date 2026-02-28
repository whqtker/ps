#include <iostream>
#include <queue>
#include <vector>

#define INF 300001

using namespace std;

int main() {
	int v, e, k;
	cin >> v >> e >> k;

	vector<pair<int, int>> nodes[20001]; // {도착 노드, 가중치}
	for (int i = 0;i < e;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		nodes[x].push_back({ y,w });
	}

	vector<int> cost(v + 1);
	for (int i = 1;i <= v;i++) {
		if (i == k)
			cost[i] = 0;
		else
			cost[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 이미 최단거리가 존재하는 경우
		if (cost[cur] < weight)
			continue;

		for (int i = 0;i < nodes[cur].size();i++) {
			if (weight + nodes[cur][i].second < cost[nodes[cur][i].first]) {
				cost[nodes[cur][i].first] = weight + nodes[cur][i].second;
				pq.push({ weight + nodes[cur][i].second ,nodes[cur][i].first });
			}
		}
	}

	for (int i = 1;i <= v;i++) {
		if (cost[i] == INF)
			cout << "INF\n";
		else
			cout << cost[i] << "\n";
	}
}