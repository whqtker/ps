#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int idx[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	int m = 0;
	int max_idx = 0;
	for (int i = 1;i <= n;i++) {
		int tmp = 0;
		for (int j = 1;j <= i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j]) {
					dp[i] = dp[j];
					tmp = j;
				}
			}
		}
		dp[i]++;
		if (dp[i] > 1)
			idx[i] = tmp;

		if (m < dp[i]) {
			m = dp[i];
			max_idx = i;
		}
	}
	cout << m << "\n";

	vector<int> v;
	for (int i = 0;i < m;i++) {
		v.push_back(arr[max_idx]);
		max_idx = idx[max_idx];
	}
	reverse(v.begin(), v.end());

	for (int i = 0;i < m;i++)
		cout << v[i] << " ";
}