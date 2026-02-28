#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
int visited[51];
int leaves;
int rnode; // 삭제한 노드
int root;

void dfs(int node) {
	// 삭제된 노드는 살펴보지 않음
	if (node == rnode) return;

	// node가 리프 노드인 경우
	if (v[node].size() == 0) leaves++;

	// 현재 노드의 유일한 자식이 삭제된 노드라면 현재 노드가 리프 노드가 됨
	if (v[node].size() == 1 && v[node][0] == rnode) leaves++;

	visited[node] = 1;

	int cnt = 0;
	for (int i = 0;i < v[node].size();i++) {
		int nnode = v[node][i];

		if (!visited[nnode]) {
			dfs(nnode);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		if (x == -1) root = i;
		else
			v[x].push_back(i);
	}

	cin >> rnode;

	dfs(root);

	cout << leaves;
}