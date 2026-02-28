#include <iostream>
#include <map>
#include <limits.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	map<long long, int> m;
	int max_v = 0;
	long long max_k = LLONG_MIN;
	for (int i = 0;i < n;i++) {
		long long x;
		cin >> x;

		if (m.find(x) != m.end()) {
			long long k = m.find(x)->first;
			int v = m.find(x)->second;
			m.erase(x);
			m.insert({ k, v + 1 });
		}

		m.insert({ x, 1 });

		if ((max_v == m.find(x)->second && max_k > x) || max_v < m.find(x)->second) {
			max_v = m.find(x)->second;
			max_k = x;
		}

	}

	cout << max_k;

}