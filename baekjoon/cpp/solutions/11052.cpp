#include <iostream>
#include <algorithm>

using namespace std;

int card[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		card[i] = a;
	}

	for (int i = 1;i <= n;i++) {
		dp[i] = card[i];
		for (int j = 1;j <= i / 2;j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];
}