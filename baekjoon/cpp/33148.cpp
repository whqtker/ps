#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	map<long long, int> m; // m[x]=y: x의 개수는 y
	vector<long long> a; // 기존 배열
	for (int i = 0; i < n * n; i++) {
		long long x;
		cin >> x;
		m[x]++;
	}

	// m에서 가장 작은 수의 제곱근은 a의 가장 작은 수이다.
	// cf) a의 원소 num의 수가 cnt개라고 m에는 num^2이 cnt^2개 존재하는 것이 아니다. 반례: A: {2, 8}
	long long min = m.begin()->first;
	long long root = sqrtl(min);
	if (root * root == min) {
		a.push_back(root);
		m[min]--;
		if (m[min] == 0)
			m.erase(min);
	}
	else {
		cout << "NO";
		return 0;
	}

	// a의 가장 작은 원소를 통해 연쇄적으로 a를 복원한다.
	// 또한 찾은 원소로 m을 만들 수 있는지 검증한다.
	for (int i = 1; i < n; i++) {
		if (m.empty()) {
			cout << "NO";
			return 0;
		}

		long long min = m.begin()->first; // min = a[0]*a[i]
		if (min % a[0] != 0) {
			cout << "NO";
			return 0;
		}
		long long cur = min / a[0];
		a.push_back(cur);

		for (int j = 0; j < i; j++) {
			// 오버플로우 감지
			if (a[j] > 0 && cur > LLONG_MAX / a[j]) {
				cout << "NO";
				return 0;
			}

			long long chk = cur * a[j];

			m[chk] -= 2; // 대칭으로 존재하므로

			if (m[chk] < 0) {
				cout << "NO";
				return 0;
			}
			else if (m[chk] == 0) {
				m.erase(chk);
			}
		}

		// a[i] * a[i]
		// 오버플로우 감지
		if (cur > 0 && cur > LLONG_MAX / cur) {
			cout << "NO";
			return 0;
		}
		long long chk = cur * cur;
		m[chk]--;

		if (m[chk] < 0) {
			cout << "NO";
			return 0;
		}
		else if (m[chk] == 0) {
			m.erase(chk);
		}
	}

	if (!m.empty()) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}