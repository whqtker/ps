#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 1;
	for (int i = 0;i < n;i++) {
		if (sum < v[i]) {
			break;
		}
		else
			sum += v[i];
	}

	cout << sum;
}