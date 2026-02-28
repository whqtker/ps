#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

int parents[1001];

int Find(int x) {
	if (parents[x] == x)
		return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	int px = parents[x];
	int py = parents[y];

	parents[px] = py;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> coor;
	coor.push_back({ 0,0 }); // 0번 인덱스 보정
	vector<pair<double, pair<int, int>>> nodes;
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		coor.push_back({ x,y });
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			double x1, y1, x2, y2;
			tie(x1, y1) = coor[i];
			tie(x2, y2) = coor[j];

			double w = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

			nodes.push_back({ w,{i,j} });
		}
	}

	for (int i = 1;i <= n;i++) {
		parents[i] = i;
	}

	int cnt = 0;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;

		if (Find(a) != Find(b)) {
			Union(a, b);
			cnt++;
		}
	}

	sort(nodes.begin(), nodes.end());

	double ans = 0;
	for (int i = 0;i < nodes.size();i++) {
		double w = nodes[i].first;
		int cur, nxt;
		tie(cur, nxt) = nodes[i].second;

		if (Find(cur) == Find(nxt))
			continue;

		Union(cur, nxt);
		ans += w;
		cnt++;

		if (cnt == n - 1)
			break;
	}

	cout.precision(2);
	cout << fixed;
	cout << ans;
}