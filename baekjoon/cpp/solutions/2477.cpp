#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int w = 0, h = 0;
	vector<int> dir;
	vector<int> len;
	for (int i = 0;i < 6;i++) {
		int d, l;
		cin >> d >> l;
		dir.push_back(d);
		len.push_back(l);

		if (d == 1 || d == 2)
			w += l;
		else
			h += l;
	}

	int idx = 0;
	for (int i = 0;i < 6;i++) {
		if (dir[i] == dir[(i + 2) % 6] && dir[(i + 1) % 6] == dir[(i + 3) % 6]) {
			idx = i;
		}
	}

	cout << ((w / 2) * (h / 2) - len[(idx + 1) % 6] * len[(idx + 2) % 6]) * n;
}