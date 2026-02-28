#include <iostream>

#define R 1000000007

using namespace std;

int main() {
	int m;
	cin >> m;

	int ans = 0;
	for (int i = 0;i < m;i++) {
		long long a, b;
		cin >> b >> a;

		// (a*b^-1) % R을 계산해야 함.
		// b^-1 = b^R-2 % R이다.
		long long res = 1;
		long long n = R - 2;
		while (n) {
			if (n % 2 == 1) {
				res *= b;
				res %= R;
			}
			b *= b;
			b %= R;
			n /= 2;
		}
		long long inv = res;
		
		ans += (a * inv) % R;
		ans %= R;
	}

	cout << ans;
}