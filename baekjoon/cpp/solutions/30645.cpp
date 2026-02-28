#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000][1000];

int main() {
	int r, c, n;
	cin >> r >> c >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.rbegin(), v.rend());

	int cnt = 0;
	int x = 0, y = 0; // x: 현재 행, y: 현재 열
	for (int i = 0; i < n; i++) {
		if (x == 0) {
			arr[x][y] = v[i];
			y++;
			cnt++;
		}
		else if (arr[x - 1][y] > v[i]) {
			arr[x][y] = v[i];
			y++;
			cnt++;
		}

		if (y >= c) {
			x++;
			y = 0;
		}
		if (x >= r)
			break;
	}

	cout << cnt;
}