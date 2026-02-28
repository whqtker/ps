#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int s;
		cin >> s;

		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			s += a * b;
		}
		cout << s << "\n";
	}
}