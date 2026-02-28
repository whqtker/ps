#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	cout << (b - a + 1) * (a + b) / 2;
}