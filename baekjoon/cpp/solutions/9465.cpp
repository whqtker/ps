#include <iostream>
#include <algorithm>

using namespace std;

int arr[3][100001];
int dp[3][100001];

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;
		for (int j = 0;j < 2 * n;j++) {
			int x;
			cin >> x;
			arr[j / n + 1][j % n + 1] = x;
		}

		for (int j = 0;j <= n;j++) {
			dp[1][j] = max(dp[2][j - 1], dp[2][j - 2]) + arr[1][j];
			dp[2][j] = max(dp[1][j - 1], dp[1][j - 2]) + arr[2][j];
		}

		cout << max(dp[1][n], dp[2][n]) << "\n";
	}
}