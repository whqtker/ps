#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;

		int idx = lower_bound(v.begin(), v.end(), x) - v.begin();

		if (idx >= n || v[idx] != x) cout << "0 ";
		else cout << "1 ";
	}
}