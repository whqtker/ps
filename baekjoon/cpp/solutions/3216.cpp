#include <iostream>

using namespace std;

int when[100001]; // 언제부터 들을 수 있는지, download의 누적 합
int download[100001];
int len[100001];
int n;

bool able(int m) {
	int cumLen = 0;
	for (int i = 1; i <= n; i++) {
		if (m + cumLen < when[i]) {
			return false;
		}

		cumLen += len[i];
	}

	return true;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int d, v;
		cin >> d >> v;

		len[i] = d;
		when[i] = when[i - 1] + v;
		download[i] = v;
	}

	int l = when[1];
	int r = when[n];
	int m;

	int ans;
	while (l <= r) {
		m = (l + r) / 2;

		if (able(m)) {
			r = m - 1;
			ans = m;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans;
}