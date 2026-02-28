#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[101];
vector<pair<int,int>> graph[101]; // {노드, 필요 부품 수}
int dp[101][101]; // i로 j를 만드는 데 필요한 기본 부품의 수
int comp[101]; // 중간 또는 최종물인지

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c; // a를 만드는 데 b가 c개 필요하다
		cin >> a >> b >> c;

		comp[a] = 1;
		graph[b].push_back({ a,c });
		inDegree[a]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			dp[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i].first; // x->y 가 cnt개
			int cnt = graph[x][i].second;
			inDegree[y]--;

			// j->y = j->x * cnt + j->y
			for (int j = 1; j <= n; j++) {
				dp[j][y] += dp[j][x] * cnt;
			}

			if (inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (comp[i] == 0) {
			cout << i << " " << dp[i][n] << "\n";
		}
	}
}