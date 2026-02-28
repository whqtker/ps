#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

// 휴게소 간 최대 거리를 x로 했을 때, 설치 가능한 휴게소의 수를 리턴
int chk(int x) {
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int gap = v[i + 1] - v[i];

		if (gap % x == 0) {
			cnt += gap / x - 1;
		}
		else {
			cnt += gap / x;
		}
	}

	return cnt;
}

int main() {
	int n, m, l;
	cin >> n >> m >> l;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	v.push_back(0);
	v.push_back(l);

	sort(v.begin(), v.end());

	int left = 1;
	int right = l;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2; // mid: 휴게소 간 최대 거리

		int cnt = chk(mid);

		if (cnt <= m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left;
}