#include <iostream>

using namespace std;

int arr[100001];
int visited[100001]; // 0: 방문X, 1: 팀 생성 가능, -1: 팀 생성 불가능
int n, start;

void dfs(int i) {
	// 순환: x에서 시작, y가 순환의 시작 => x부터 y 전까지 visited를 -1로 변경
	// 단 x와 y와 같은 경우 pass
	// 순환 발생 여부: 접근하려고 하는 사람이 이미 방문한(y) 경우

	if (visited[i]) {
		if (i == start)
			return;
		while (start != i) {
			visited[start] = -1;
			start = arr[start];
		}
		return;
	}

	visited[i] = 1;
	dfs(arr[i]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> arr[i];
		}

		for (int i = 1;i <= n;i++) {
			start = i;
			if (visited[i] == 0) {
				dfs(i);
			}
		}

		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (visited[i] != 1)
				cnt++;
			visited[i] = 0;
		}

		cout << cnt << "\n";
	}
}