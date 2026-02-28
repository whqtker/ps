#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000001

using namespace std;

int main() {
	int n, m, x; // 마을의 수, 간선, 시작 마을
	cin >> n >> m >> x;
	
	vector<pair<int, int>> forward[1001]; // x에서 각 마을로 돌아갈 때 사용
	vector<pair<int, int>> backward[1001]; // 역방향 간선, 각 마을에서 x로 갈 때 사용
	for (int i = 0;i < m;i++) {
		int s, e, t;
		cin >> s >> e >> t;
		forward[s].push_back({ t,e });
		backward[e].push_back({ t,s });
	}

	vector<int> back(n + 1); // 돌아올 때 걸리는 최소 거리
	for (int i = 1;i <= n;i++) {
		if (i == x)
			back[i] = 0;
		else
			back[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (back[cur] < weight)
			continue;

		for (int i = 0;i < forward[cur].size();i++) {
			if (weight + forward[cur][i].first < back[forward[cur][i].second]) {
				back[forward[cur][i].second] = weight + forward[cur][i].first;
				pq.push({ back[forward[cur][i].second],forward[cur][i].second });
			}
		}
	}

	vector<int> go(n + 1); // 갈 때 걸리는 최소 거리
	for (int i = 1;i <= n;i++) {
		if (i == x)
			go[i] = 0;
		else
			go[i] = INF;
	}

	pq.push({ 0,x });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (go[cur] < weight)
			continue;

		for (int i = 0;i < backward[cur].size();i++) {
			if (weight + backward[cur][i].first < go[backward[cur][i].second]) {
				go[backward[cur][i].second] = weight + backward[cur][i].first;
				pq.push({ go[backward[cur][i].second],backward[cur][i].second });
			}
		}
	}

	int ans = 0;
	for (int i = 1;i <= n;i++) {
		ans = max(ans, go[i] + back[i]);
	}
	cout << ans;
}