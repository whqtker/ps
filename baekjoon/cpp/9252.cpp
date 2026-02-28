#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001][1001];

int main() {
	string a, b;
	cin >> a >> b;

	int m = 0;
	int s = 0;
	for (int i = 0;i < a.length();i++) {
		for (int j = 0;j < b.length();j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				if (dp[i + 1][j] > dp[i][j + 1]) {
					dp[i + 1][j + 1] = dp[i + 1][j];
				}
				else {
					dp[i + 1][j + 1] = dp[i][j + 1];
				}
			}

			if (dp[i + 1][j + 1] > m) {
				m = dp[i + 1][j + 1];
			}
		}
	}

	if (m == 0)
		cout << m;
	else {
		cout << m << "\n";
		int x = a.length();
		int y = b.length();
		vector<char> ans;

		while (x >= 0 && y >= 0) {
			if (dp[x - 1][y] == dp[x][y])
				x--;
			else if (dp[x][y - 1] == dp[x][y])
				y--;
			else {
				ans.push_back(a[x - 1]);
				x--;
				y--;
			}
		}

		for (int i = ans.size()-1;i >=0;i--) {
			cout << ans[i];
		}
	}
}