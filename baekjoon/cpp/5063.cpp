#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int r, e, c; // r: 광고를 하지 않았을 때 수익, e: 광고를 했을 때 수익, c: 광고 비용
		cin >> r >> e >> c;

		// e - c가 광고를 했을 때 순수익이다.
		if (r > e - c) cout << "do not advertise\n";
		else if (r < e - c) cout << "advertise\n";
		else cout << "does not matter\n";
	}
}