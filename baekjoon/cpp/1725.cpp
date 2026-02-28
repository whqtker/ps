#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;

int sol(int s, int e) {
	if (s == e)
		return 0;
	if (s + 1 == e)
		return v[s];

	int mid = (s + e) / 2;
	int ans = max(sol(s, mid), sol(mid, e));

	int w = 1;
	int h = v[mid];
	int l = mid;
	int r = mid;
	while (1) {
		if (r - l > e - s)
			break;
		int lh = l - 1 >= s ? min(h,v[l - 1]) : -1;
		int rh = r + 1 < e ? min(h,v[r + 1]) : -1;

		if (lh > rh) {
			l--;
			h = lh;
		}
		else {
			r++;
			h = rh;
		}
		w++;
		ans = max(ans, w * h);
	}

	return ans;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	cout << sol(0, n);
}