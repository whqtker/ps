#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cost[1001]; // 건설 비용
int dp[1001];
vector<int> node[1001]; // 노드 간 연결 관계
int inDegree[1001]; // 진입차수

void clear() {
	for (int i = 0; i < 1001; i++) {
		cost[i] = 0;
		dp[i] = 0;
		node[i].clear();
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		clear();

		int n, k, w;
		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}

		for (int i = 1; i <= n; i++) {
			dp[i] = cost[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			node[x].push_back(y);
			inDegree[y]++;
		}

		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!inDegree[i]) {
				q.push(i);
				dp[i] = cost[i];
			}
		}

		for (int i = 1; i <= n; i++) {
			int x = q.front();
			q.pop();

			for (int j = 0; j < node[x].size(); j++) {
				int y = node[x][j];
				inDegree[y]--;
				dp[y] = max(dp[y], dp[x] + cost[y]);
				if (!inDegree[y])
					q.push(y);
			}
		}

		cout << dp[w] << "\n";
	}
}