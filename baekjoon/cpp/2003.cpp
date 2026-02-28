#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int l = 0, r = 0, sum = v[0], cnt = 0;
	while (1) {
		if (sum > m) {
			sum -= v[l];
			l++;
		}
		else if (sum < m) {
			r++;
			if (r >= n)
				break;
			sum += v[r];
		}
		else {
			cnt++;
			sum -= v[l];
			l++;
		}
	}

	cout << cnt;
}