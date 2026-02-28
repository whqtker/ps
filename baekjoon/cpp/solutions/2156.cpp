#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001][3]; // dp[i][j]: i번 째 잔을 마셨을 때 최대 포도주의 양, 현재 연속하여 j잔 마신 상태

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	int tmp = 0; // 1번 째 잔부터 i - 2번 째 잔까지의 dp 최댓값
	int m = 0; // 최종 최댓값
	for (int i = 1;i <= n;i++) {
		if (i - 2 > 0)
			tmp = max({ tmp, dp[i - 2][1], dp[i - 2][2] });

		dp[i][1] = tmp + arr[i];
		if (i - 1 > 0)
			dp[i][2] = dp[i - 1][1] + arr[i];

		m = max({ m, dp[i][1], dp[i][2] });
	}

	cout << m;
}