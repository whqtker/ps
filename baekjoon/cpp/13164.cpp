#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first > b.first;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<pair<int,int>> gap; // gap[i].second: gap[i].first번 째 수와 다음 수의 차이
	int tmp;
	cin >> tmp;
	v.push_back(tmp);

	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		gap.push_back({ i,x - tmp });
		tmp = x;
	}

	if (k == 1) {
		cout << v[n - 1] - v[0];
		return 0;
	}

	sort(gap.begin(), gap.end(), cmp);

	vector<int> idx;
	for (int i = 0; i < k - 1; i++) {
		idx.push_back(gap[i].first);
	}
	
	sort(idx.begin(), idx.end());

	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (i == 0) {
			ans += v[idx[i]] - v[0];
		}
		else if (i == k - 1) {
			ans += v[n - 1] - v[idx[i - 1] + 1];
		}
		else {
			ans += v[idx[i]] - v[idx[i - 1] + 1];
		}
	}

	cout << ans;
}