#include <iostream>
#include <algorithm>

#define INF 2147483647

using namespace std;

int dp[500][500]; // dp[i][j]: i번째 행렬부터 j번째 행렬까지 곱한 값의 최솟값
int r[501];
int c[501];

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		r[i] = x;
		c[i] = y;
	}

	for (int i = 1;i < n;i++) {
		for (int j = 0;i + j < n;j++) {
			dp[j][i + j] = INF;
			for (int k = j;k <= i + j;k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + r[j] * c[k] * c[i + j]);
			}
		}
	}

	cout << dp[0][n - 1];
}