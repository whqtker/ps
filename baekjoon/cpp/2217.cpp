#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	vector<int> ans;
	for (int i = 0;i < n;i++) {
		ans.push_back(v[i] * (n - i));
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1];
}