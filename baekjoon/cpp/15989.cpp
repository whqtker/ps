#include <iostream>

using namespace std;

int dp[10001][4]; // dp[i][j]: i를 만드는 경우의 수, 가장 작은 수는 j

int main() {
	int T;
	cin >> T;

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 2;
	dp[3][2] = 0;
	dp[3][3] = 1;

	for (int i = 4;i <= 10000;i++) {
		dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
		dp[i][2] = dp[i - 2][2] + dp[i - 2][3];
		dp[i][3] = dp[i - 3][3];
	}

	while (T--) {
		int x;
		cin >> x;
		cout << dp[x][1] + dp[x][2] + dp[x][3] << "\n";
	}
}