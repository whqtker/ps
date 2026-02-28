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

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0;i < v.size();i++) {
		int l = 0;
		int r = v.size() - 1;

		while (l < r) {
			if (v[l] + v[r] == v[i]) {
				if (l == i)
					l++;
				else if (r == i)
					r--;
				else {
					ans++;
					break;
				}
			}
			else if (v[l] + v[r] > v[i]) {
				r--;
			}
			else if (v[l] + v[r] < v[i]) {
				l++;
			}
		}
	}

	cout << ans;
}