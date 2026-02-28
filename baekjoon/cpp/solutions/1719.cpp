#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 10000001

using namespace std;

vector<pair<int, int>> nodes[201];
int dist[201];
int arr[201][201]; // 가장 먼저 이동해야 할 집하장 배열

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		nodes[a].push_back({ b,w });
		nodes[b].push_back({ a,w });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[j] = INF;
		}

		dist[i] = 0;
		pq.push({ 0,i,0 });

		while (!pq.empty()) {
			int weight = get<0>(pq.top());
			int node = get<1>(pq.top());
			int first = get<2>(pq.top());
			pq.pop();

			if (dist[node] < weight)
				continue;

			for (int j = 0; j < nodes[node].size(); j++) {
				int nnode = nodes[node][j].first;
				int nweight = nodes[node][j].second;

				if (dist[nnode] > weight + nweight) {
					dist[nnode] = weight + nweight;

					if (!first)
						arr[i][nnode] = nnode;
					else
						arr[i][nnode] = first;

					pq.push({ dist[nnode],nnode,arr[i][nnode] });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}