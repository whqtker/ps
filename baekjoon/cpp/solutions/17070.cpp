#include <iostream>

using namespace std;

int arr[16][16];
int dp[16][16][3]; // d][i][j][x]에서 x=0: 가로, x=1: 세로, x=2: 대각선

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][1][0] = 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (j - 1 >= 0 && !arr[i][j] && !arr[i][j - 1]) {
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			}

			if (i - 1 >= 0 && !arr[i][j] && !arr[i - 1][j]) {
				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			}

			if (j - 1 >= 0 && i - 1 >= 0) {
				if (!arr[i - 1][j - 1] && !arr[i - 1][j] && !arr[i][j - 1]) {
					dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}
	}

	if (arr[n - 1][n - 1] == 1)
		cout << 0;
	else
		cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}