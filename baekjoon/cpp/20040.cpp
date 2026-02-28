#include <iostream>

using namespace std;

int parents[500001];

int Find(int x) {
	if (x == parents[x])
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(parents[x]);
	y = Find(parents[y]);

	if (x != y)
		parents[x] = y;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		if (Find(x) == Find(y)) {
			cout << i + 1;
			return 0;
		}

		Union(x, y);
	}
	cout << 0;
}