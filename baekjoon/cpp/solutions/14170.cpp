#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << (upper_bound(v.begin(), v.end(), e) - v.begin()) - (lower_bound(v.begin(), v.end(), s) - v.begin()) << "\n";
	}
}