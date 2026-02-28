#include <iostream>
#include <map>

using namespace std;

int ps1[1001][1001]; // ps1[i][j]: i번 째 수부터 j번 째 수까지 누적 합
int ps2[1001][1001];

int main() {
	int t;
	cin >> t;

	map<int, long long> m1; // <누적 합, 누적 합의 수>
	map<int, long long> m2;

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		for (int j = 1; j <= i; j++) {
			ps1[j][i] = ps1[j][i - 1] + x;

			m1[ps1[j][i]]++;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;

		for (int j = 1; j <= i; j++) {
			ps2[j][i] = ps2[j][i - 1] + x;

			m2[ps2[j][i]]++;
		}
	}

	long long ans = 0;
	for (auto iter : m1) {
		auto cur = m2.find(t - iter.first);
		if (cur != m2.end()) {
			ans += iter.second * cur->second;
		}
	}

	cout << ans;
}