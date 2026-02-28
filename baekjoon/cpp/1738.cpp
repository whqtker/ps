#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define INF 1e9

using namespace std;

int dist[101];
int rev[101];
int visited[101];

void dfs(int node, const vector<tuple<int,int,int>>& edges) {
	for (int i = 0; i < edges.size(); i++) {
		int start = get<0>(edges[i]);
		int end = get<1>(edges[i]);

		if (node == start && !visited[end]) {
			visited[end] = 1;
			dfs(end, edges);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,-c }); // 가중치 부호를 반전시켜 최소 비용 문제로 변환
	}

	for (int i = 2; i <= n; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			if (dist[start] + w < dist[end]) {
				dist[end] = dist[start] + w;
				rev[end] = start;
			}
		}
	}

	// 1 -> 음의 사이클 -> n 이어야 불가능한 경우이다.
	for (int j = 0; j < edges.size(); j++) {
		int start = get<0>(edges[j]);
		int end = get<1>(edges[j]);
		int w = get<2>(edges[j]);

		// 1 -> 음의 사이클 경로가 있는가?
		if (dist[start] + w < dist[end]) {
			// 음의 사이클 -> n 경로가 있는가?
			visited[end] = 1;
			dfs(end, edges);

			if (visited[n]) {
				cout << -1;
				return 0;
			}
		}
	}

	vector<int> ans;
	int node = n;
	while (node != 0) {
		ans.push_back(node);
		node = rev[node];
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}