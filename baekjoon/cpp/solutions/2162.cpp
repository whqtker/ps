#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> P, Q;
int parent[3000];
int cnt[3000];

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[x] = y;
}

double ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

bool meet(int a, int b) {
	pair<int, int> A = P[a];
	pair<int, int> B = Q[a];
	pair<int, int> C = P[b];
	pair<int, int> D = Q[b];

	if (ccw(A, B, C) * ccw(A, B, D) <= 0 && ccw(C, D, A) * ccw(C, D, B) <= 0) {
		if (ccw(A, B, C) * ccw(A, B, D) == 0 && ccw(C, D, A) * ccw(C, D, B) == 0) {
			return (A <= D && C <= B);
		}
		else
			return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		P.push_back({ a,b });
		Q.push_back({ c,d });

		// P[i]가 Q[i]보다 x 또는 y 좌표가 더 작도록 유지한다.
		if (P[i] > Q[i])
			swap(P[i], Q[i]);

		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 두 선분의 부모가 다르면 교차하는지 확인
			if (parent[i] != parent[j]) {
				if (meet(i, j))
					Union(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		parent[i] = Find(parent[i]);
	}

	for (int i = 0; i < n; i++) {
		cnt[parent[i]]++;
	}

	int max_cnt = 0;
	int group_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] > 0)
			group_cnt++;
		max_cnt = max(max_cnt, cnt[i]);
	}
	cout << group_cnt << "\n" << max_cnt;
}