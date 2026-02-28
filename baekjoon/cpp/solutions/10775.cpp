#include <iostream>

using namespace std;

int parents[100001];

int Find(int x) {
	if (parents[x] == x)
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);

	if (px < py)
		parents[py] = px;
	else
		parents[px] = py;

}

int main() {
	int g, p;
	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;

		int px = Find(x);

		if (px == 0) {
			cout << i;
			return 0;
		}
		else {
			Union(px, px - 1);
		}
	}
	cout << g;
}