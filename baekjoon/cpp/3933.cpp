#include <iostream>

#define MAX 32768

using namespace std;

int dp[32768];

// 이전 값, 최소 밑, 개수
void recur(int prev, int base, int k) {
	if (k == 0) {
		int base = 1;
		while (base * base < MAX) {
			dp[base * base]++;
			recur(base * base, base, k + 1);
			base++;
		}
		return;
	}

	if (k == 4) {
		return;
	}

	while (prev + base * base < MAX) {
		dp[prev + base * base]++;
		recur(prev + base * base, base, k + 1);
		base++;
	}
}

int main() {
	recur(0, 0, 0);

	while (1) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		cout << dp[n] << "\n";
	}
}