#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; // n개의 동전, 목표 금액 k원
	cin >> n >> k;

	vector<int> v; // 동전 금액
	int idx = 0; // k원보다 작은 동전 중 가장 큰 동전의 인덱스
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);

		if (x <= k)idx = i;
	}

	int cnt = 0;
	for (int i = idx; i >= 0; i--) {
		while (k - v[i] >= 0) {
			k -= v[i];
			cnt++;
		}
	}

	cout << cnt;
}