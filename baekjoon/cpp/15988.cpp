#include <iostream>

using namespace std;

long long dp[1000001];

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int j = 4;j <= n;j++)
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;

		cout << dp[n] << "\n";
	}
}