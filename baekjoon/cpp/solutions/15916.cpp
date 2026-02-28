#include <iostream>

using namespace std;

int arr[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	long long k;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		long long prev = (long long)k * (i - 1) - arr[i - 1];
		long long cur = (long long)k * i - arr[i];

		if (i == 1) {
			if (cur == 0) { // y=kx 위에 있는 경우
				cout << "T";
				return 0;
			}
		}
		else {
			if (prev == 0 || cur == 0 || (prev < 0 && cur > 0) || (prev > 0 && cur < 0)) {
				cout << "T";
				return 0;
			}
		}
	}

	cout << "F";
}