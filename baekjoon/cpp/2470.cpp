#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

	sort(v.begin(), v.end());

	int l = 0; int r = n - 1, gap = 2e9 + 1;
	int first = 0, second = 0;
	while (l < r) {
		if (abs(v[l] + v[r]) < gap) {
			first = v[l];
			second = v[r];
			gap = abs(v[l] + v[r]);

			if (v[l] + v[r] >= 0)
				r--;
			else
				l++;
		}
		else {
			if (v[l] + v[r] >= 0)
				r--;
			else
				l++;
		}
	}

	cout << first << " " << second;
}