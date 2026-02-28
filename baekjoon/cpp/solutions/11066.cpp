#include <iostream>
#include <algorithm>

using namespace std;

int s[500]; // 장의 크기
int dp[500][500]; // dp[i][j]: i장에서부터 j장까지 합쳤을 때 최소 비용
int sum[500]; // 누적 합

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0;i < n;i++) {
			cin >> s[i];
		}

		sum[0] = s[0];
		for (int i = 1; i < n; i++) {
			sum[i] = sum[i - 1] + s[i];
		}

		// dp[i][j] = min(dp[i][i] + dp[i + 1][j], dp[i][i + 1] + dp[i + 2][j], ..., dp[i][j - 1] + dp[j][j])
		// i장부터 j장까지 최소 비용 계산, 순서 주의
		for (int j = 0;j < n;j++) {
			for (int i = j - 1;i >= 0; i--) {
				dp[i][j] = 2e8;
				for (int k = i;k < j;k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
				dp[i][j] += sum[j] - (i > 0 ? sum[i - 1] : 0);
			}
		}

		cout << dp[0][n - 1] << "\n";
	}
}