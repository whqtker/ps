#include <iostream>
#include <map>

#define R 1000000007

using namespace std;

map<long long, long long> m;

// f(m+n) = f(m-1)f(n)+f(m)f(n+1), 도가뉴 항등식
long long fibo(long long n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	long long x = n / 2;
	long long a = 0, b = 0, ans = 0;

	// m = n, f(2m) = f(m)(2f(m-1)+f(m))
	if (n % 2 == 0) {
		if (m.find(x) == m.end())
			a = fibo(x);
		else
			a = m[x];

		if (m.find(x - 1) == m.end())
			b = fibo(x - 1);
		else
			b = m[x - 1];

		ans = (a * ((2 * b) % R + a) % R) % R;
	}
	// n = m-1, f(2m-1) = f(m)^2+f(m-1)^2
	else {
		if (m.find(x) == m.end())
			a = fibo(x);
		else
			a = m[x];

		if (m.find(x + 1) == m.end())
			b = fibo(x + 1);
		else
			b = m[x + 1];

		ans = ((a * a % R) % R + (b * b % R) % R) % R;
	}

	m[n] = ans;
	return ans;
}

int main() {
	long long n;
	cin >> n;

	m[0] = 0;
	m[1] = 1;
	cout << fibo(n);
}