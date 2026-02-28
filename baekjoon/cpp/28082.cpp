#include <iostream>
#include <algorithm>
#include <vector>

#define INF 50001

using namespace std;

int arr[500];
int dp[INF]; // dp[i] = x: 전력량 i를 만들기까지 사용한 최소 배터리의 수

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i < INF;i++) {
		dp[i] = INF;
	}

	for (int i = 0;i < n;i++) {
		for (int j = INF - arr[i];j >= 0;j--) {
			dp[j + arr[i]] = min(dp[j + arr[i]], dp[j] + 1);
		}
	}

	int cnt = 0;
	for (int i = 1;i < INF;i++) {
		if (dp[i] <= k)
			cnt++;
	}
	cout << cnt << "\n";

	for (int i = 1;i < INF;i++) {
		if (dp[i] <= k)
			cout << i << " ";
	}
}