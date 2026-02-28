#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0;i < n;i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	long long gap = 3e9 + 1;
	int a = 0, b = 1, c = 2;
	for (int i = 0;i < n - 2;i++) {
		long long goal = -v[i]; // v[i] + v[l] + v[r]이 0에 가까워야 함
		int l = i + 1, r = n - 1;
		while (l < r) {
			// 저장된 최솟값보다 더 작으면
			if (abs(v[i] + v[l] + v[r]) < gap) {
				a = i;
				b = l;
				c = r;
				gap = abs(v[i] + v[l] + v[r]);

				if (v[l] + v[r] >= goal)
					r--;
				else
					l++;
			}
			else {
				if (v[l] + v[r] >= goal)
					r--;
				else
					l++;
			}
		}
	}

	cout << v[a] << " " << v[b] << " " << v[c];
}