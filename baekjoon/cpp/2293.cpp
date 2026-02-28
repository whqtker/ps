#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1);
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
	}

	dp[0] = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = v[i];j <= k;j++) {
			dp[j] += dp[j - v[i]];
		}
	}

	cout << dp[k];
}