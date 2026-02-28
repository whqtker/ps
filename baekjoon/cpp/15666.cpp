#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int input[8];
int arr[8];

void bt(int k) {
	if (m == k) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0;i < n;i++) {
		int x = input[i];
		if (x != prev) {
			if (k - 1 < 0 || x >= arr[k - 1]) {
				arr[k] = x;
				prev = x;
				bt(k + 1);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> input[i];
	}

	sort(input, input + n);
	bt(0);
}