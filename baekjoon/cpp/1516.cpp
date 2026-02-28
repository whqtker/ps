#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int t[501]; // 건물을 짓는 데 걸리는 시간
vector<int> nodes[501];
int inDegree[501];
int dp[501];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		cin >> t[i];

		while (1) {
			int x;
			cin >> x;
			if (x == -1) break;

			nodes[x].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1;i <= n;i++) {
		if (!inDegree[i]) {
			q.push(i);
			dp[i] = t[i];
		}
	}

	for (int i = 0;i < n;i++) {
		int x = q.front();
		q.pop();

		for (int j = 0;j < nodes[x].size();j++) {
			int y = nodes[x][j];
			inDegree[y]--;
			dp[y] = max(dp[y], dp[x] + t[y]);

			if (!inDegree[y]) {
				q.push(y);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		cout << dp[i] << "\n";
	}
}