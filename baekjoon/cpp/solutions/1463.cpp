#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp(1000001);

int calc(int x) {
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}
	return dp[x];
}

int main() {
	int n;
	cin >> n;

	cout << calc(n);
}