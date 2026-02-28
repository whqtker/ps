#include <iostream>
#include <algorithm>

using namespace std;

int cost[21]; // 홍보 비용
int customer[21]; // 유치 고객 수
int dp[100001]; // dp[i]: i 비용으로 얻을 수 있는 최대 고객 수

int main() {
	int c, n; // 최소 고객 유치 수, 도시의 수
	cin >> c >> n;

	for (int i = 0;i < n;i++) {
		cin >> cost[i] >> customer[i];
	}

	for (int i = 0;i < n;i++) {
		for (int j = 1;j <= 100001;j++) {
			if (j - cost[i] >= 0) {
				dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
			}
		}
	}

	for (int i = 1;i <= 100001;i++) {
		if (dp[i] >= c) {
			cout << i;
			break;
		}
	}
}