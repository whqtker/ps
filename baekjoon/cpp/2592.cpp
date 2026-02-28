#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int sum = 0;
	vector<int> v(1000);
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		sum += x;
		v[x]++;
	}

	int maxIdx = max_element(v.begin(), v.end()) - v.begin();
	cout << sum / 10 << "\n" << maxIdx;
}