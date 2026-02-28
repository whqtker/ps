#include <iostream>
#include <vector>

using namespace std;

vector<int> conn[100001]; // 노드 간 연결 관계를 저장하는 벡터
vector<int> child[100001]; // 자식 노드를 저장하는 벡터
int parent[100001]; // 부모 노드를 저장하는 벡터
int cnt[100001];

// 자식 및 부모 관계 설정
void makeTree(int cur,int par) {
	for (int i = 0; i < conn[cur].size(); i++) {
		int node = conn[cur][i];
		if (node != par) {
			parent[node] = cur;
			child[cur].push_back(node);
			makeTree(node, cur);
		}
	}
}

// 서브트리의 노드 개수 세기
void countNodes(int cur) {
	cnt[cur] = 1;
	for (int i = 0; i < child[cur].size(); i++) {
		countNodes(child[cur][i]);
		cnt[cur] += cnt[child[cur][i]];
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, r, q; // 노드의 수, 루트 노드 번호, 쿼리 수
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		conn[x].push_back(y);
		conn[y].push_back(x);
	}

	parent[r] = -1;
	makeTree(r, -1);

	countNodes(r);

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << cnt[x] << "\n";
	}
}