#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, h;
int line[31][11]; // line[i][j]: 높이 i에 가로선 (j, j + 1)이 존재함.
int ans = 4;

bool ladder() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			// 출발 세로선: i, 높이: j

			// 높이 j에 (cur, cur + 1) 가로선이 존재하면
			if (line[j][cur]) {
				cur++;
			}
			// 높이 j에 (cur, cur - 1) 가로선이 존재하면
			else if (cur - 1 >= 1 && line[j][cur - 1]) {
				cur--;
			}
		}

		// 출발 i, 도착 i가 아니면
		if (cur != i)
			return false;
	}

	return true;
}

void dfs(int cnt,int curH,int curX) {
	if (cnt >= ans) {
		return;
	}

	if (ladder()) {
		ans = min(ans, cnt);
		return;
	}

	if (cnt == 3) {
		return;
	}

	for (int i = curH; i <= h; i++) {
		int start = 0;
		if (i == curH)
			start = curX;
		else
			start = 1;

		for (int j = start; j < n; j++) {
			if (line[i][j]) continue;
			if (line[i][j - 1]) continue;
			if (line[i][j + 1]) continue;

			line[i][j] = 1;

			dfs(cnt + 1, i, j + 2);

			line[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		line[a][b] = 1;
	}

	dfs(0, 1, 1);

	if (ans == 4) cout << -1;
	else cout << ans;
}