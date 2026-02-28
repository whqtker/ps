#include <iostream>

using namespace std;

int n[8];

int main() {
	for (int i = 0;i < 4;i++) {
		int a, s, d, f, g, h, j, k;
		cin >> a >> s >> d >> f >> g >> h >> j >> k;
		n[0] = a;
		n[1] = s;
		n[2] = d;
		n[3] = f;
		n[4] = g;
		n[5] = h;
		n[6] = j;
		n[7] = k;

		if ((n[0] == n[6] && n[1] == n[7]) || (n[2] == n[4] && n[1] == n[7]) || (n[2] == n[4] && n[3] == n[5]) || (n[0] == n[6] && n[3] == n[5])) {
			cout << "c" << "\n";
			continue;
		}
		if (((n[3] == n[5] && n[2] > n[4]) && (n[3] == n[5] && n[6] > n[0])) || ((n[6] == n[0] && n[3] > n[5]) && (n[6] == n[0] && n[7] > n[1])) 
			|| ((n[7] == n[1] && n[6] > n[0]) && (n[7] == n[1] && n[2] > n[4])) || ((n[2] == n[4] && n[7] > n[1]) && (n[2] == n[4] && n[3] > n[5]))) {
			cout << "b" << "\n";
			continue;
		}
		if (n[2] < n[4] || n[3] < n[5] || n[6] < n[0] || n[7] < n[1]) {
			cout << "d" << "\n";
			continue;
		}
		else
			cout << "a" << "\n";
	}
}