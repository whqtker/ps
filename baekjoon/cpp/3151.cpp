#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int want = -v[i] - v[j];

			if (lower_bound(v.begin() + j + 1, v.end(), want) - v.begin() >= n)
				continue;

			if (v[lower_bound(v.begin() + j + 1, v.end(), want) - v.begin()] == want) {
				cnt += (upper_bound(v.begin() + j + 1, v.end(), want) - v.begin()) - (lower_bound(v.begin() + j + 1, v.end(), want) - v.begin());
			}

		}
	}

	cout << cnt;
}