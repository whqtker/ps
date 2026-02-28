#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int idx = 1;
	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		vector<vector<int>> v(n, vector<int>(3, 0));
		for (int i = 0;i < n;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[i][0] = a;
			v[i][1] = b;
			v[i][2] = c;
		}

		vector<vector<int>> dp(n, vector<int>(3, 0));
		dp[1][0] = v[0][1] + v[1][0];
		dp[1][1] = min({ v[0][1], v[0][1] + v[0][2], v[0][1] + v[1][0]}) + v[1][1];
		dp[1][2] = min({ v[0][1] + v[0][2], v[0][1], v[0][1] + v[1][0] + v[1][1],v[0][1] + v[1][1] }) + v[1][2];

		for (int i = 2;i < n;i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][0];
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}) + v[i][1];
			dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + v[i][2];
		}

		cout << idx << ". " << dp[n - 1][1] << "\n";
		idx++;
	}
}