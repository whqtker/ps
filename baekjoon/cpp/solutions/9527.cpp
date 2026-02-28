#include <iostream>
#include <cmath>

using namespace std;

long long arr[54]; // arr[i]: MSB가 i보다 같거나 작은 수들의 1의 개수, 10^16의 비트 수는 54개

long long sum(long long x) {
	long long ans = 0;

	// 최상단 비트부터 접근
	for (int i = 54; i >= 0; i--) {
		// 만약 x의 i번 째 비트가 1이라면
		if (x & (1LL << i)) {
			ans += arr[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ans;
}

int main() {
	long long a, b;
	cin >> a >> b;

	arr[0] = 1;
	for (int i = 1; i < 55; i++) {
		arr[i] = 2 * arr[i - 1] + (1LL << i);
	}

	cout << sum(b) - sum(a - 1);
}