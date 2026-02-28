#include <iostream>

using namespace std;

int n, m;
int arr[8];

void bt(int k) {
	if (m == k) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (k - 1 < 0 || arr[k - 1] <= i) {
			arr[k] = i;
			bt(k + 1);
		}
	}
}

int main() {
	cin >> n >> m;

	bt(0);
}