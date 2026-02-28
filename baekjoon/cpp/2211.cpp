#include <iostream>
#include <vector>
#include <queue>

#define INF 10001

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> nodes[1001];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}

	vector<int> cost(n + 1);
	for (int i = 2; i <= n; i++) {
		cost[i] = INF;
	}

	// 슈퍼컴퓨터로부터 다른 컴퓨터 간 최소 시간을 구한다.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,1 });

	vector<int> parent(1001); // 최단 경로를 역추적하기 위한 배열

	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (cost[node] < weight)
			continue;

		for (int i = 0; i < nodes[node].size(); i++) {
			int nnode = nodes[node][i].first;
			int nweight = nodes[node][i].second;

			if (weight + nweight < cost[nnode]) {
				cost[nnode] = weight + nweight;
				parent[nnode] = node;
				pq.push({ cost[nnode],nnode });
			}
		}
	}

	// n개의 노드를 가지는 그래프의 최소 간선의 수는 n - 1개이다 (spanning tree)
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << " " << i << "\n";
	}
}