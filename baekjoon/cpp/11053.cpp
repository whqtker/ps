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

	vector<int> dp;
	int max = 0;
	for (int i = 0;i < n;i++) {
		int length = 0;
		for (int j = 0;j < i;j++) {
			if (v[i] > v[j])
				length = (length > dp[j]) ? length : dp[j];
		}
		dp.push_back(length + 1);
		max = (dp[i] > max) ? dp[i] : max;
	}

	cout << max;
}