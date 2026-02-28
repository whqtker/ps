#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
	int z;
	while (y != 0) {
		z = x % y;
		x = y;
		y = z;
	}
	return x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int tmp = x;
		int ans = -1;
		while (tmp <= lcm(m, n)) {
			if ((tmp - 1) % n + 1 == y) // 나누어 떨어지는 경우 방지
				ans = tmp;
			tmp += m;
		}
		cout << ans << "\n";
	}
}