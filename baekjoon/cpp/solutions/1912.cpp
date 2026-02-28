#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000];
int arr[100000];

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	dp[0] = arr[0];
	int m = dp[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > m)
			m = dp[i];
	}
	cout << m;

}