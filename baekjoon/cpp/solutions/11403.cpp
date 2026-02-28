#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			if (x == 0)
				v[i].push_back(100);
			else if (i == j)
				v[i].push_back(0);
			else
				v[i].push_back(x);
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (v[i][j] > 0 && v[i][j] < 100)
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";
	}
}