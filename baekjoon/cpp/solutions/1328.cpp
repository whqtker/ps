#include <iostream>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll dp[101][101][101];

int main() {
	int n, l, r;
	cin >> n >> l >> r;

	dp[1][1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][1][i] = 1; // i, i - 1, ..., 2, 1으로 순차적 배치
		dp[i][i][1] = 1; // 1, 2, ..., i - 1, i으로 순차적 배치
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
				dp[i][j][k] %= MOD;
			}
		}
	}

	cout << dp[n][l][r];
}