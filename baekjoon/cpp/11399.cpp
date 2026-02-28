#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());

	int t = 0;
	for (int i = 0; i < n; i++) {
		t += v[i] * (v.size() - i);
	}
	cout << t;
}