#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int incr[1000];
int decr[1000];

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		incr[i] = 1;
		decr[i] = 1;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i;j++) {
			if (arr[j] < arr[i]) {
				incr[i] = max(incr[j] + 1, incr[i]);
			}
		}
	}

	for (int i = n - 1;i >= 0;i--) {
		for (int j = n - 1;j > i;j--) {
			if (arr[j] < arr[i]) {
				decr[i] = max(decr[j] + 1, decr[i]);
			}
		}
	}

	int ans = -1;
	for (int i = 0;i < n;i++) {
		ans = max(ans, incr[i] + decr[i] - 1);
	}
	cout << ans;
}