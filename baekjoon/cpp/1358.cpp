#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	double w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;

	vector<int> px;
	vector<int> py;
	for (int i = 0;i < p;i++) {
		int a, b;
		cin >> a >> b;
		px.push_back(a);
		py.push_back(b);
	}

	int cnt = 0;
	for (int i = 0;i < p;i++) {
		bool cond1 = pow(px[i] - x, 2) + pow(py[i] - h / 2 - y, 2) <= pow(h / 2, 2);
		bool cond2 = pow(px[i] - x - w, 2) + pow(py[i] - h / 2 - y, 2) <= pow(h / 2, 2);
		bool cond3 = px[i] >= x && px[i] <= x + w && py[i] >= y && py[i] <= y + h;

		if (cond1 || cond2 || cond3)
			cnt++;
	}
	cout << cnt;
}