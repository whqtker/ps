#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		vector<int> cx;
		vector<int> cy;
		vector<int> r;
		for (int j = 0;j < n;j++) {
			int a, b, c;
			cin >> a >> b >> c;
			cx.push_back(a);
			cy.push_back(b);
			r.push_back(c);
		}

		int cnt = 0;
		for (int j = 0;j < n;j++) {
			bool startIsIn = pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2) < pow(r[j], 2);
			bool endIsIn = pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2) < pow(r[j], 2);

			if (startIsIn != endIsIn)
				cnt++;
		}

		cout << cnt << "\n";
	}
}