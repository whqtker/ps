#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, c;
	cin >> n >> c;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int l = 1; // 공유기 사이 거리 최소값
	int r = v[n - 1] - v[0]; // 공유기 사이 거리 최대값
	int ans = 0; // 인접 공유기 사이 최대 거리

	while (l <= r) {
		int m = (l + r) / 2; // 인접 공유기 사이 최대 거리 후보값

		// 첫 번째 집에는 반드시 공유기를 설치한다.
		int cnt = 1;
		int s = v[0]; // 직전 공유기 설치 위치
		for (int i = 1;i < n;i++) {
			if (v[i] - s >= m) {
				cnt++;
				s = v[i];
			}
		}

		if (cnt >= c) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans;
}