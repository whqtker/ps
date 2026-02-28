#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001]; // dp[i][j]: i부터 j까지의 수가 팰린드롬이면 1, 그렇지 않으면 0

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i <= n;i++) {
		// s와 e가 같은 경우 무조건 팰린드롬이다.
		dp[i][i] = 1;

		// s와 e가 1 차이나는 경우 두 수가 같으면 팰린드롬이다.
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	// s와 e가 2 이상 차이나는 경우 두 수가 같고 s - 1부터 e + 1까지의 수가 팰린드롬이면 팰린드롬이다.
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; i + j <= n; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
				dp[j][i + j] = 1;
		}
	}

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}