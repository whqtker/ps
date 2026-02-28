#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	vector<vector<int>> ans(n, vector<int>(n, 0)); // ans[i][j]: i번 학생이 j번 학생과 같은 반이었던 횟수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < n; k++) {
				if (v[i][j] == v[k][j] && i != k) ans[i][k]++;
			}
		}
	}

	vector<int> sum(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] > 0)
				sum[i] ++;
		}
	}

	cout << max_element(sum.begin(), sum.end()) - sum.begin() + 1;

}