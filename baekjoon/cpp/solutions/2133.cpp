#include <iostream>

using namespace std;

int dp[31];

int main() {
	int n;
	cin >> n;

	// dp[n] = dp[n-2]*3 + sum(dp[n-4] ~ dp[2]) * 2 + 2
	// n이 홀수면 항상 0
	if (n % 2 == 1) cout << 0;
	else {
		dp[2] = 3;
		for (int i = 4;i <= 30;i += 2) {
			dp[i] = dp[i - 2] * 3;

			for (int j = 4;i - j > 0;j += 2) {
				dp[i] += dp[i - j] * 2;
			}

			dp[i] += 2;
		}

		cout << dp[n];
	}
}