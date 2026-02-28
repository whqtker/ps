#include <iostream>
#include <algorithm>

using namespace std;

int arr[1002][1002];
int dp[1002][1002];
int L[1002][1002];
int R[1002][1002];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	// 처음 행은 오른쪽은 불가능
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= m; i++) {
		dp[1][i] = dp[1][i - 1] + arr[1][i];
	}

	for (int i = 2; i <= n; i++) {
		// 왼쪽, 오른쪽 초기화
		L[i][1] = dp[i - 1][1] + arr[i][1];
		for (int j = 2; j <= m; j++) {
			L[i][j] = max(L[i][j - 1], dp[i - 1][j]) + arr[i][j];
		}

		R[i][m] = dp[i - 1][m] + arr[i][m];
		for (int j = m - 1; j >= 1; j--) {
			R[i][j] = max(R[i][j + 1], dp[i - 1][j]) + arr[i][j];
		}

		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(L[i][j], R[i][j]);
		}
	}

	cout << dp[n][m];
}