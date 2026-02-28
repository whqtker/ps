#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	double l; // 치킨의 수, 시소의 길이
	cin >> n >> l;

	vector<double> d; // 치킨의 거리
	double WX = 0;
	double W = 0;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		d.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		W += x;
		WX += d[i] * x;
	}

	cout << fixed;
	cout.precision(6);
	cout << WX / W;
}