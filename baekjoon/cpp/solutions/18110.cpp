#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0)
		cout << 0;
	else {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());
		double sum = 0;
		for (int i = round(n * 0.15); i <= n - 1 - round(n * 0.15); i++) {
			sum += v[i];
		}
		cout << round(sum / (n - 2 * round(n * 0.15)));
	}
}