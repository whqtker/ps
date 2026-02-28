#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> e; // 예상 등수
	vector<int> r; // 실제 등수

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		e.push_back(x);
		r.push_back(i + 1);
	}

	sort(e.begin(), e.end());
	sort(r.begin(), r.end());

	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(e[i] - r[i]);
	}
	cout << ans;
}