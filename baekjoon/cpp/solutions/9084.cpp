#include <iostream>

using namespace std;

int coin[20];
int dp[10001][20]; // dp[i][j]: i를 만드는 방법의 수, 만드는 방법에서 가장 작은 수는 coin[j]

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			coin[j] = x;
			dp[x][j] = 1;
		}

		int target;
		cin >> target;
		for (int j = 1;j <= target;j++) {
			for (int k = 0;k < n;k++) {
				if (j - coin[k] > 0) {
					for (int l = k;l < n;l++) {
						dp[j][k] += dp[j - coin[k]][l];
					}
				}
			}
		}

		int sum = 0;
		for (int j = 0;j < n;j++) {
			sum += dp[target][j];
		}
		cout << sum << "\n";

		for (int j = 0;j < 20;j++) {
			coin[j] = 0;
		}
		for (int j = 0;j < 10001;j++) {
			for (int k = 0;k < 20;k++)
				dp[j][k] = 0;
		}
	}
}