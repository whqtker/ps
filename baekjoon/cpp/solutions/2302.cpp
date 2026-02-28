#include <iostream>

using namespace std;

int dp[41]; // dp[i]: 좌석이 i개일 때 앉을 수 있는 경우의 수, VIP 석 제외
int vip[41];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= m;i++) {
		int x;
		cin >> x;
		vip[x] = 1;
	}

	for (int i = 0;i <= 41;i++) {
		dp[i] = 1;
	}

	if (vip[1] != 1 && vip[2] != 1) {
		dp[2] = 2;
	}

	int sum = 1;
	for (int i = 3;i <= n;i++) {
		if (vip[i] != 1) {
			if (vip[i - 1] == 1)
				dp[i] = 1;
			else if (vip[i - 2] == 1)
				dp[i] = 2;
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		else {
			sum *= dp[i - 1];
		}
	}
	cout << sum * dp[n];
}