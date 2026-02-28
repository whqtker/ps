#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// m: v에서 1씩 증가하는 부분수열의 최대 길이
	// 답은 n - m 이다.
	unordered_map<int, int>dp; // dp[i]: i로 끝나는 1씩 증가하는 부분수열의 최대 길이
	int m = -1;
	for (int i = 0; i < n; i++) {
		int cur = v[i];

		// cur - 1에 대한 정보가 있다면
		if (dp.count(cur - 1))
			dp[cur] = dp[cur - 1] + 1;
		else
			dp[cur] = 1;

		m = max(dp[cur], m);
	}

	cout << n - m;
}