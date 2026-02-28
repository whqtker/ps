#include <iostream>
#include <algorithm>

using namespace std;

int v[1000]; // 봉사활동 가산점
int dp[2001][1000]; // dp[i][j]: i일까지의 최대 가산점, 헌혈 j번 함

int main() {
	int n, m, a, d; // n: 남은 일수, m: 필요한 가산점, a: 헌혈 가산점, d: 헌혈 후 쉬어야 하는 날
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> a >> d;

	dp[0][0] = v[0];
	dp[d - 1][1] = a;

	int ans = 1001;
	for (int i = 1;i < n;i++) {
		for (int j = 0;j <= i;j++) {
			// 봉사활동을 하는 경우
			// 전날 최대 가산점이 존재하지 않는 경우
			if (dp[i - 1][j] == 0)
				continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i]);
			if (dp[i][j] >= m)
				ans = min(ans, j);

			// 헌혈을 하는 경우, 헌혈 후 쉬는 날 고려, 쉬는 날은 dp 초기화 X
			dp[i + d - 1][j + 1] = max(dp[i + d - 1][j + 1], dp[i - 1][j] + a);
			if (dp[i + d - 1][j + 1] >= m)
				ans = min(ans, j + 1);

		}
	}

	if (ans == 1001)
		cout << -1;
	else
		cout << ans;
}