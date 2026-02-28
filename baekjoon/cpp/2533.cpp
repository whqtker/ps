#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes[1000001]; // 노드 연결 관계
int dp[1000001][2]; // dp[i][j]: i번 째 노드가 얼리 어답터가 아닐 때(j == 0) 또는 얼리 어답터일 때(j == 1) 최소 얼리 어답터

void dfs(int node, int parent) {
	dp[node][0] = 0;
	dp[node][1] = 1;

	for (int i = 0; i < nodes[node].size(); i++) {
		int child = nodes[node][i];

		if (child == parent)
			continue;

		dfs(child, node);

		dp[node][0] += dp[child][1]; // node가 얼리 어답터가 아닌 경우 자식은 무조건 얼리 어답터여야 함.
		dp[node][1] += min(dp[child][0], dp[child][1]); // node가 얼리 어답터인 경우 자식은 얼리 어답터일 수도 있고 아닐 수도 있음
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x].push_back(y);
		nodes[y].push_back(x);
	}

	dfs(1, -1);
	cout << min(dp[1][0], dp[1][1]);
}