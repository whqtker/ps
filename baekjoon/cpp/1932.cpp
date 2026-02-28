#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
int v[501][501];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
		}
	}

	cout << *max_element(dp[n], dp[n] + n + 1);
}