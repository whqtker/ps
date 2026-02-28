#include <iostream>
#include <string.h>

using namespace std;

int arr[501];

int main() {
	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {
		int p, m;
		cin >> p >> m;

		int cnt = 0;
		memset(arr, 0, sizeof(int) * 501);
		for (int j = 0;j < p;j++) {
			int x;
			cin >> x;

			if (arr[x] == 1)
				cnt++;
			else
				arr[x] = 1;
		}

		cout << cnt << "\n";
	}
}