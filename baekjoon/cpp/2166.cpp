#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	vector<long long> x;
	vector<long long> y;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		long long a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	long double ans = 0;
	for (int i = 0;i < n;i++) {
		ans += x[i % n] * y[(i + 1) % n];
		ans -= x[(i + 1) % n] * y[i % n];
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) / 2;
}