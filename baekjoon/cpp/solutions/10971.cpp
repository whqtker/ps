#include <iostream>
#include <algorithm>

using namespace std;

int arr[11][11];
int visited[11];
int n;
int min_value = 10000001;

// 현재 노드, 방문 횟수, 현재 노드까지 총 비용
void dfs(int cur, int cnt,int val) {
	if (val >= min_value)
		return;

	if (cnt == n) {
		if (arr[cur][0])
			min_value = min(min_value, val + arr[cur][0]);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[cur][i] && !visited[i]) {
			visited[i] = 1;
			dfs(i, cnt + 1, val + arr[cur][i]);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	visited[0] = 1;
	dfs(0, 1, 0);

	cout << min_value;
}