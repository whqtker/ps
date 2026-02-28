#include <iostream>

using namespace std;

int main() {
	int arr[9];
	int sum = 0;
	for (int i = 0;i < 9;i++) {
		int x;
		cin >> x;
		arr[i] = x;
		sum += x;
	}

	sum -= 100;
	int a = 0, b = 0;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < i;j++) {
			if (arr[i] + arr[j] == sum) {
				a = i;
				b = j;
			}
		}
	}

	for (int i = 0;i < 9;i++) {
		if (i != a && i != b)
			cout << arr[i] << "\n";
	}
}