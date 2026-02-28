#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> factors;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		factors.push_back(x);
	}

	sort(factors.begin(), factors.end());

	if (n % 2 == 1) {
		cout << (long long)pow(factors[n / 2], 2);
	}
	else {
		cout << (long long)(factors[n / 2 - 1] * factors[n / 2]);
	}
}