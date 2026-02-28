#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	double sum = -1;
	vector<double> v;
	for (int i = 0;i < n;i++) {
		double x;
		cin >> x;
		v.push_back(x);

		double tmp = 1;
		for (int j = i;j >= 0;j--) {
			tmp *= v[j];
			if (tmp > sum)
				sum = tmp;
		}
	}

	cout << fixed;
	cout << setprecision(3) << sum;
}