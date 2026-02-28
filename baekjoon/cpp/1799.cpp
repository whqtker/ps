#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> board[20]; // board[i]: i번 째 우상향 대각선을 지나는 좌표들, i = 0은 (0, 0)을 지남, i = x + y
int ans = 0;
int rightUp[20];
int rightDown[20];

void bt(int k, int idx) {
	if (idx >= 2 * n - 1) {
		ans = max(ans, k);
		return;
	}

	bool flag = false;
	for (int i = 0; i < board[idx].size(); i++) {
		int x = board[idx][i].first;
		int y = board[idx][i].second;

		if (!rightUp[x + y] && !rightDown[x - y + n - 1]) {
			flag = true;
			rightUp[x + y] = 1;
			rightDown[x - y + n - 1] = 1;
			bt(k + 1, idx + 1);
			rightUp[x + y] = 0;
			rightDown[x - y + n - 1] = 0;
		}
	}

	if (!flag) {
		bt(k, idx + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			
			if (x) {
				board[i + j].push_back({i, j});
			}
		}
	}

	bt(0, 0);
	cout << ans;
}