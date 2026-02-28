#include <iostream>
#include <cmath>

using namespace std;

int dp[1001][10]; // dp[i][j]

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0;i <= 9;i++) {
		dp[1][i] = 1;
		sum += dp[1][i];
	}

	for (int i = 2;i <= n;i++) {
		sum = 0;
		for (int j = 0;j <= 9;j++) {
			for (int k = 0;k <= j;k++) {
				dp[i][j] += dp[i - 1][k] % 10007;
				dp[i][j] %= 10007;
				sum += dp[i - 1][k] % 10007;
				sum %= 10007;
			}
		}
	}

	cout << sum;
}