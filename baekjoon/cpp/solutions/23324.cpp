#include <iostream>
#include <unordered_map>;

using namespace std;

int parent[100001];

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int px = Find(parent[x]);
	int py = Find(parent[y]);

	if (px != py) {
		parent[px] = py;
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		// 연결된 간선이 0인 경우만 합친다.
		if (i != k) {
			Union(a, b);
		}
	}

	unordered_map<int, long long> um;
	for (int i = 1; i <= n; i++) {
		um[Find(i)]++;
	}

	if (um.size() == 1) {
		cout << 0;
	}
	else {
		long long ans = 1;
		for (auto e : um) {
			ans *= e.second;
		}

		cout << ans;
	}
}