#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][10101]; // dp[x][y]: x: x번째의 앱 처리, y: 총 비활성화 비용, dp[x][y]: 메모리 확보한 공간의 크기(m보다 커야 함)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<int> a, c;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		c.push_back(x);
	}

	int ans = 10001;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= 10000;j++) {
			int tmp = dp[2][0];
			// 현재 앱 비활성화
			if (dp[i - 1][j] < m)
				dp[i][j + c[i - 1]] = max(dp[i][j + c[i - 1]], dp[i - 1][j] + a[i - 1]);

			// 현재 앱 pass
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			// 충분히 공간을 확보한 경우
			if (dp[i][j] >= m) {
				ans = min(ans, j);
			}
		}
	}

	cout << ans;
}