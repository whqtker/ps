#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> house(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			int x;
			cin >> x;
			house[i].push_back(x);
		}
	}

	// dp[i][0]: i번 째 집을 R로 칠할 때 최소 비용
	// dp[i][1]: i번 째 집을 G로 칠할 때 최소 비용
	// dp[i][2]: i번 째 집을 B로 칠할 때 최소 비용
	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1;i < n;i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
}