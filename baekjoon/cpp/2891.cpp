#include <iostream>

using namespace std;

int arr[11];

int main() {
	int n, s, r;
	cin >> n >> s >> r;
	for (int i = 0; i < s; i++) {
		int x;
		cin >> x;
		arr[x]--;
	}
	for (int i = 0; i < r; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] < 0) {
			if (i - 1 > 0 && arr[i - 1] > 0) {
				arr[i]++;
				arr[i - 1]--;
			}
			else if (i + 1 <= n && arr[i + 1] > 0) {
				arr[i]++;
				arr[i + 1]--;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] < 0)
			ans++;
	}

	cout << ans;
}