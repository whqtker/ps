#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += v[i - 1].first * i + v[i - 1].second;
	}
	cout << ans;
}