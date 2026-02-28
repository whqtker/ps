#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n;
vector<pair<int, int>> v[10001];
int visited[10001];
int ans = 0;
int endNode = 0;

void dfs(int s,int len) {
	if (visited[s])
		return;

	visited[s] = 1;

	if (ans < len) {
		ans = len;
		endNode = s;
	}

	for (int i = 0;i < v[s].size();i++) {
		dfs(v[s][i].first, len + v[s][i].second);
	}
}

int main() {
	// 가장 멀리 떨어져있는 노드를 찾고 지름을 계산한다.
	cin >> n;

	for (int i = 0;i < n - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	// 가장 멀리 있는 노드 찾기
	dfs(1, 0);

	// 지름 계산하기
	ans = 0;
	memset(visited, 0, sizeof(visited));
	dfs(endNode, 0);
	cout << ans;
}