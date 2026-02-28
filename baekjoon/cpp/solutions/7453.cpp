#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[4]; // A, B, C, D
vector<int> sum[2]; // A+B, C+D

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			v[j].push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[0].push_back(v[0][i] + v[1][j]);
			sum[1].push_back(v[2][i] + v[3][j]);
		}
	}

	sort(sum[0].begin(), sum[0].end());
	sort(sum[1].begin(), sum[1].end());

	long long cnt = 0;
	for (int i = 0; i < sum[0].size(); i++) {
		int tar = lower_bound(sum[1].begin(), sum[1].end(), -sum[0][i]) - sum[1].begin();
		int len = upper_bound(sum[1].begin(), sum[1].end(), -sum[0][i]) - sum[1].begin();
		if (tar < sum[1].size() && sum[0][i] + sum[1][tar] == 0)
			cnt += len - tar;
	}

	cout << cnt;
}