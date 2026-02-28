#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int candy[30001];
int parents[30001];
int people[30001]; // 그룹에 속하는 아이의 수
int dp[30001][3001];

int Find(int x) {
	if (x == parents[x])
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);

	if (x < y)
		parents[y] = x;
	else
		parents[x] = y;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, k; // 아이 수, 친구 관계 수, 최소 아이 수
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		parents[i] = i;
		people[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= n; i++) {
		if (parents[i] != i) {
			int p = Find(i);
			candy[p] += candy[i];
			people[p] += people[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (parents[i] == i) {
			for (int j = 1; j < k; j++) {
				if (people[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], candy[i] + dp[i - 1][j - people[i]]);
			}
		}
		else {
			for (int j = 1; j < k; j++) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k - 1];
}