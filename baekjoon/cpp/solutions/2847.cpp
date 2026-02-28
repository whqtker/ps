#include <iostream>
#include <vector>

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

	int cnt = 0;
	for (int i = n - 1;i > 0;i--) {
		if (v[i] <= v[i - 1]) {
			cnt += v[i - 1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}

	cout << cnt;
}