#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <tuple>

#define INF 1e9

using namespace std;

int s, g, h; // 출발지, g - h 간선을 반드시 지남
vector<int> cost(2001);
vector<pair<int, int>> nodes[2001]; // nodes[x] = {y, w}: x -> y 간선의 가중치는 w

void init(int n) {
	for (int i = 0; i <= n; i++) {
		nodes[i].clear();
	}
}

void dijkstra(int n) {
	for (int i = 1; i <= n; i++) {
		cost[i] = INF;
	}
	cost[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;

		pq.pop();

		if (cost[x] < w)
			continue;

		for (int i = 0; i < nodes[x].size(); i++) {
			int y = nodes[x][i].first;
			int nw = nodes[x][i].second;

			if (w + nw < cost[y]) {
				cost[y] = w + nw;
				pq.push({ cost[y],y });
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m, t; // 교차로, 도로, 목적지 후보
		cin >> n >> m >> t;

		cin >> s >> g >> h;

		init(n);

		for (int i = 0; i < m; i++) {
			int a, b, d; // a - b 간선의 가중치는 d / 양방향
			cin >> a >> b >> d;

			// 필수 경로는 가중치를 홀수로 설정
			if ((a == g && b == h) || (a == h && b == g)) {
				nodes[a].push_back({ b,d * 2 - 1 });
				nodes[b].push_back({ a,d * 2 - 1 });
			}

			// 필수 경로가 아니라면 가중치를 짝수로 설정
			nodes[a].push_back({ b,d * 2 });
			nodes[b].push_back({ a,d * 2 });
		}

		set<int> candidate;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			candidate.insert(x);
		}

		// s -> candidate[i]로 최단거리로 이동할 때, g - h 간선을 지나면 답, 그렇지 않으면 답 X
		dijkstra(n);

		for (auto dest : candidate) {
			// 만약 최소 비용이 홀수면 필수 경로를 지난 것임.
			if (cost[dest] % 2)
				cout << dest << " ";
		}
		cout << "\n";
	}
}