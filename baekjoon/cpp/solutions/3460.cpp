#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int digit = 0;
		while (n != 0) {
			if (n % 2 == 1) {
				cout << digit << " ";
			}
			digit++;
			n /= 2;
		}
	}
}