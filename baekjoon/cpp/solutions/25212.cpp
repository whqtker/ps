#include <iostream>

using namespace std;

int n;
double cake[10];
int ans = 0;

// 현재 idx, 누적 합
void recur(int pos, double sum) {
	if (pos == n) {
		if (sum >= 0.99 && sum <= 1.01)
			ans++;
		return;
	}

	// 다음 케이크 선택 안함
	recur(pos + 1, sum);

	// 다음 케이크 선택함
	recur(pos + 1, sum + cake[pos]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cake[i] = 1.0 / x;
	}

	recur(0, 0.0);
	cout << ans;
}