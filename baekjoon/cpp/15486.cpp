#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500001]; // dp[i]: i일까지의 최대 수익
int date[1500001];
int pay[1500001];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		int t, p;
		cin >> t >> p;
		date[i] = t;
		pay[i] = p;
	}

	int ans = 0;
	for (int i = 1;i <= n + 1;i++) {
		dp[i] = max(ans, dp[i]);
		dp[i + date[i]] = max(dp[i + date[i]], dp[i] + pay[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
}