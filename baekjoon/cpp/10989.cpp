#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int arr[10001] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}
}