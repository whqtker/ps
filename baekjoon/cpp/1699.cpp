#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < 100001;i++) {
		dp[i] = 100001;
	}

	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= (int)sqrt(i);j++) {
			dp[i] = min(dp[i], dp[i - (int)pow(j, 2)]);
		}
		dp[i]++;
	}

	cout << dp[n];
}