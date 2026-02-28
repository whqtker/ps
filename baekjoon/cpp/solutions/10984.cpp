#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		int tot = 0;
		double gpa = 0;
		for (int j = 0; j < n; j++) {
			int c;
			double g;
			cin >> c >> g;

			tot += c;
			gpa += c * g;
		}
		cout << fixed;
		cout.precision(1);
		cout << tot << " " << gpa / tot << "\n";
	}
}