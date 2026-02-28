#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	vector<int> dp; // dp[i]: v[i]까지의 가장 큰 증가하는 수열의 합
	int max = 0;
	for (int i = 0;i < n;i++) {
		int sum = 0;
		int tmp = 0;
		for (int j = 0;j < i;j++) {
			if (v[i] > v[j]) {
				tmp = dp[j];
				sum = (tmp > sum) ? tmp : sum;
			}
		}
		dp.push_back(v[i] + sum);
		max = (dp[i] > max) ? dp[i] : max;
	}

	cout << max;
}