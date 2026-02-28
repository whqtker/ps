#include <iostream>
#include <algorithm>

#define MAX_VAL 1000000

using namespace std;

int prime[MAX_VAL + 1];

int main() {
	fill(prime, prime + MAX_VAL + 1, 1);
	for (int i = 2; i <= MAX_VAL; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= MAX_VAL; j += i)
				prime[j] = 0;
		}
	}
	int n;
	cin >> n;

	// 모든 순열에서 인접한 두 수의 집합이 (1, 소수) 이고, 어느 쌍이라도 비내림차순을 만족하지 않는다면 불가능
	int a, b;
	cin >> a;
	bool allOneAndPrime = true;
	bool allNonDesc = true;
	for (int i = 0; i < n - 1; i++) {
		cin >> b;

		if (!((a == 1 && prime[b]) || (prime[a] && b == 1)))
			allOneAndPrime = false;

		if (a > b)
			allNonDesc = false;

		a = b;
	}

	if (allOneAndPrime && !allNonDesc) cout << "NO";
	else cout << "YES";
}