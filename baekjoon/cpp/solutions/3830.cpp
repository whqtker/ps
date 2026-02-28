#include <iostream>

using namespace std;

int n, m; // 샘플의 수, 한 일의 수
int parent[100001];
int weight[100001]; // weight[i]: i와 루트 간 무게 차이

int Find(int x) {
	if (x == parent[x]) return x;

	int root = Find(parent[x]);
	weight[x] += weight[parent[x]];
	return parent[x] = root;
}

void Union(int x, int y, int w) {
	int px = Find(x);
	int py = Find(y);

	if (px != py) {
		// 루트가 변함에 따라 weight를 보정한다.
		// px의 부모를 py로 설정하고, px가 루트인 모든 노드에 px->py (offset) 가중치를 더한다.
		// 루트가 px인 임의의 노드를 x, 루트가 py인 임의의 노드를 y라고 하자.
		// 알고 있는 정보: x->y, x->px, y->py
		// x->px->py == x->y->py에서 px->py의 가중치 offset = w + weight[y] - weight[x]
		int offset = w + weight[y] - weight[x];
		weight[px] = offset;
		parent[px] = py;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 정보를 서로 안다면 부모는 서로 같다.
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1;i <= n;i++) {
			parent[i] = i;
			weight[i] = 0;
		}

		for (int i = 0;i < m;i++) {
			char cmd;
			cin >> cmd;

			if (cmd == '!') {
				int a, b, w; // b가 a보다 w만큼 무겁다.
				cin >> a >> b >> w;

				Union(b, a, w);
			}
			else if (cmd == '?') {
				int a, b; // b가 a보다 얼마나 무거운가?
				cin >> a >> b;

				int pa = Find(a);
				int pb = Find(b);

				if (pa != pb) cout << "UNKNOWN\n";
				else {
					cout << weight[b] - weight[a] << "\n";
				}
			}
		}
	}
}