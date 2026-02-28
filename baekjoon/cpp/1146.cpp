#include <iostream>

#define MOD 1000000

using namespace std;

int dp[101][101][2];
// dp[i][j][k]: 현재까지 i개 수를 나열했고, 현재 배치한 수가 배치한 수들 중 j번째로 작은 수이며,
// k 상태인 경우 경우의 수 (k == 0: 다음 수는 이보다 작은 수 배치)

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	// dp[i][j][0] = sum(dp[i-1][k][1]) for j <= k <= i-1
	// dp[i][j][1] = sum(dp[i-1][k][0]) for 1 <= k <= j-1
	dp[1][1][0] = 1;
	dp[1][1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= j - 1; k++) {
				dp[i][j][1] += dp[i - 1][k][0];
				dp[i][j][1] %= MOD;
			}

			for (int k = j; k <= i - 1; k++) {
				dp[i][j][0] += dp[i - 1][k][1];
				dp[i][j][0] %= MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[n][i][0] + dp[n][i][1];
		ans %= MOD;
	}

	cout << ans;
}