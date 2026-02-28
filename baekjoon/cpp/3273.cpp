#include <iostream>
#include <vector>
#include <algorithm>

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

	int t;
	cin >> t;

	sort(v.begin(), v.end());
	int cnt = 0;
	int l = 0;
	int r = n - 1;

	while (l < r) {
		if (v[l] + v[r] == t) {
			cnt++;
			l++;
			r--;
		}
		else if (v[l] + v[r] < t) {
			l++;
		}
		else if (v[l] + v[r] > t) {
			r--;
		}
	}
	cout << cnt;
}