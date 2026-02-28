#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	multimap<double, int> m;
	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		m.insert({ sqrt(pow(a, 2) + pow(b, 2)) / c,i + 1 });
	}

	for (auto i : m)
		cout << i.second << "\n";
}