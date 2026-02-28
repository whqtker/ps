#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	long long ans = 0;
	sort(v.rbegin(), v.rend());
	for (int i = 1; i <= n; i++) {
		if (v[i - 1] - i + 1 >= 0)
			ans += v[i - 1] - i + 1;
	}
	cout << ans;
}