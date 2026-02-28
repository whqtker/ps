#include <iostream>

using namespace std;

unsigned long long dp[101][10][1 << 10]; // dp[i][j][k]: 길이가 i인 계단 수의 개수, 마지막 수는 j, k는 비트필드

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}

	unsigned long long cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1 << 10; k++) {
				if (dp[i - 1][j][k] != 0) {
					if (j - 1 >= 0)
						dp[i][j - 1][k | (1 << j - 1)] += dp[i - 1][j][k] % 1000000000;

					if (j + 1 <= 9)
						dp[i][j + 1][k | (1 << j + 1)] += dp[i - 1][j][k] % 1000000000;
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j < 1 << 10; j++) {
			if (j == (1 << 10) - 1) {
				cnt += dp[n][i][j];
				cnt %= 1000000000;
			}
		}
	}

	cout << cnt;
}