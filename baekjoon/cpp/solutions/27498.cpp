#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int visited[10001];
vector<pii> graph[100001]; // { 노드, 가중치, flag }

int main() {
	int n, m;
	cin >> n >> m;

	int sum = 0; // 전체 가중치의 합, 이후 mst에서 sum을 빼면 포기한 간선의 가중치의 최솟값이 도출됨.
	int mst = 0; // MST를 이루는 간선의 가중치 합
	priority_queue<pii> pq;

	for (int i = 0; i < m; i++) {
		int a, b, w, f;
		cin >> a >> b >> w >> f;

		sum += w;

		// 끊어지면 안 되는 관계의 가중치에 최댓값을 더해 무조건 뽑히도록
		if (f == 1) {
			w += 1e4;
		}

		graph[a].push_back({ b,w });
		graph[b].push_back({ a,w });
	}

	pq.push({ 0,1 });

	while (!pq.empty()) {
		int w = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited[node]) continue;

		visited[node] = 1;
		if (w > 1e4) w -= 1e4;
		mst += w;

		for (auto edge : graph[node]) {
			int nnode = edge.first;
			int nw = edge.second;

			if (!visited[nnode]) {
				pq.push({ nw,nnode });
			}
		}
	}

	cout << sum - mst;
}