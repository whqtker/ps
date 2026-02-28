#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
vector<int> rev_graph[10001];
stack<int> s;
int visited[10001];
int rev_visited[10001];
vector<int> ans[10001];
int cnt = 0;

void dfs(int n) {
	if (visited[n])
		return;

	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++) {
		dfs(graph[n][i]);
	}

	s.push(n);
}

void rev_dfs(int n) {
	if (rev_visited[n])
		return;

	rev_visited[n] = 1;
	ans[cnt].push_back(n);

	for (int i = 0; i < rev_graph[n].size(); i++) {
		rev_dfs(rev_graph[n][i]);
	}
}

int main(){
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b); // a -> b
		rev_graph[b].push_back(a); // b -> a
	}

	// 코사라주 알고리즘
	// 1. 탐색 수행, 종료 시 해당 노드 스택에 삽입
	for (int i = 1; i <= v; i++) {
		dfs(i);
	}

	// 2. s.top()부터 dfs 수행
	while (!s.empty()) {
		if (!rev_visited[s.top()]) {
			rev_dfs(s.top());
			
			sort(ans[cnt].begin(), ans[cnt].end());
			cnt++;
		}

		s.pop();
	}

	sort(ans, ans + cnt);

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << -1 << "\n";
	}
}