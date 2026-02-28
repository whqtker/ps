#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> nodes[100001];
int visited[100001];

int main() {
	int n, m;
	cin >> n >> m;

	int start;
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ c,b });
		nodes[b].push_back({ c,a });

		start = a;
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0;i < nodes[start].size();i++) {
		pq.push(nodes[start][i]);
	}
	visited[start] = 1;

	int i = 0;
	int max_w = 0;
	int ans = 0;
	while (i < n - 1) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (!visited[v]) {
			i++;
			visited[v] = 1;
			ans += w;
			max_w = max_w < w ? w : max_w;

			for (int j = 0;j < nodes[v].size();j++) {
				if (!visited[nodes[v][j].second])
					pq.push(nodes[v][j]);
			}
		}
	}

	cout << ans - max_w;
}