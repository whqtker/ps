#include <iostream>

using namespace std;

int dp[1025][1025]; // (0, 0)부터 (i, j)까지 누적 합
int arr[1025][1025];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 1;i < n;i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}

	for (int i = 1;i < n;i++) {
		for (int j = 1;j < n;j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0;i < m;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int ans = dp[c - 1][d - 1];
		if (a - 2 >= 0)
			ans -= dp[a - 2][d - 1];
		if (b - 2 >= 0)
			ans -= dp[c - 1][b - 2];
		if (a - 2 >= 0 && b - 2 >= 0)
			ans += dp[a - 2][b - 2];

		cout << ans << "\n";
	}
}