#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int team = 0;
	while (n >= 2 || m >= 1) {
		n -= 2;
		m -= 1;
		if (n + m < k) break;
		else if (n < 0 || m < 0) break;
		else team++;

	}
	cout << team;
}