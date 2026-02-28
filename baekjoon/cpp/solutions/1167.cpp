#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int>> nodes[100001];
int visited[100001];
int ans = 0;
int endNode = 0;

void dfs(int cur,int len) {
	if (visited[cur])
		return;
	visited[cur] = 1;

	if (ans < len) {
		ans = len;
		endNode = cur;
	}

	for (int i = 0; i < nodes[cur].size(); i++) {
		dfs(nodes[cur][i].first, len + nodes[cur][i].second);
	}
}

int main() {
	int v;
	cin >> v;
	for (int i = 0; i < v; i++) {
		int s;
		cin >> s;
		while (1) {
			int e, w;
			cin >> e;
			if (e == -1)
				break;

			cin >> w;
			nodes[s].push_back({ e,w });
		}
	}

	// 가장 멀리 떨어진 노드 찾기
	dfs(1, 0);

	ans = 0;
	memset(visited, 0, sizeof(visited));

	dfs(endNode, 0);
	cout << ans;
}