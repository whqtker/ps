#include <iostream>

#define MOD 1000000007

using namespace std;

long long fact[4000001];

long long divconq(long long a, int r) {
	if (r == 0) return 1;

	long long half = divconq(a, r / 2);
	long long ret = (half * half) % MOD;

	if (r % 2 == 1) ret = (ret * a) % MOD;

	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	
	cout << (fact[n] * divconq((fact[n - k] * fact[k]) % MOD, MOD - 2)) % MOD;
}