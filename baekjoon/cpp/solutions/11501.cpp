#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	for(int i = 0;i < t;i++) {
		int n;
		cin >> n;

		vector<int> v;
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		long long profit = 0;
		int m = 0;
		for (int j = n - 1;j >= 0;j--) {
			m = max(m, v[j]);
			profit += m - v[j];
		}

		cout << profit << "\n";
	}
}