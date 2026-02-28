#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int tmp = n;
	int digit = 0;
	while (n > 0) {
		digit++;
		n /= 10;
	}

	int sum = 0;
	for (int i = 1; i < digit; i++) {
		sum += 9 * i * (pow(10, i - 1));
	}

	sum += (tmp - pow(10, digit - 1) + 1) * digit;

	cout << sum;
}