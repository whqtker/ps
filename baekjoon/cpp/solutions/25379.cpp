#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	long long even = 0, odd = 0;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			even += i - cnt;
			cnt++;
		}
	}

	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			odd += i - cnt;
			cnt++;
		}
	}
	cout << min(even, odd);
}