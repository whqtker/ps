#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int input[8];

void bt(int k) {
	if (m == k) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0;i < n;i++) {
		int x = input[i];
		if (k - 1 < 0 || arr[k - 1] <= x) {
			arr[k] = x;
			bt(k + 1);
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