#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000000

using namespace std;

vector<pair<long long, long long>> nodes[1001];
long long dist[1001];
int city[1001]; // city[x] = y: x까지 도달하는 최소 거리는 y에서 시작한다.

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		nodes[s].push_back({ e,c });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		if (i == start)
			dist[i] = 0;
		else
			dist[i] = INF;
	}

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < w)
			continue;

		for (int i = 0;i < nodes[cur].size();i++) {
			if (dist[nodes[cur][i].first] > w + nodes[cur][i].second) {
				dist[nodes[cur][i].first] = w + nodes[cur][i].second;
				pq.push({ dist[nodes[cur][i].first] ,nodes[cur][i].first });
				city[nodes[cur][i].first] = cur;
			}
		}
	}

	cout << dist[end] << "\n";
	vector<int> v;

	v.push_back(end);
	while (city[end]) {
		v.push_back(city[end]);
		end = city[end];
	}

	cout << v.size() << "\n";

	for (int i = v.size() - 1;i >= 0;i--) {
		cout << v[i] << " ";
	}
}