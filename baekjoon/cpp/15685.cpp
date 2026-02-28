#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gen[4][11]; // gen[d][g]: 초기 방향이 d이고 세대가 g인 커브에서 다음 좌표로의 방향
int board[101][101];

int main() {
	// 우, 하, 좌, 상을 편의 상 0, 1, 2, 3이라고 하자.
	// gen X가 (x1, x2, x3, ..)와 같은 형태일 때, gen X+1을 구하는 방법은 다음과 같다.
	// 1. 시계 방향 90도 회전은 (xi + 1) % 4로 구한다.
	// 2. xn부터 역순으로 반전시키고 (상 <-> 하 / 좌 <-> 우) : (xi + 2) % 4
	// 3. 그 결과를 gen X 뒤에 붙이면 gen X+1이 된다.

	gen[0][0].push_back({ 0 });
	gen[1][0].push_back({ 1 });
	gen[2][0].push_back({ 2 });
	gen[3][0].push_back({ 3 });

	for (int i = 1; i <= 10; i++) {
		for (int d = 0; d < 4; d++) {
			vector<int> next = gen[d][i - 1];
			for (int j = 0; j < next.size(); j++) {
				next[j] = (next[j] + 1) % 4;
			}

			reverse(next.begin(), next.end());

			for (int j = 0; j < next.size(); j++) {
				next[j] = (next[j] + 2) % 4;
			}

			gen[d][i] = gen[d][i - 1];
			gen[d][i].insert(gen[d][i].end(), next.begin(), next.end());
		}
	}

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		// 문제에서 1은 상, 3은 하이므로 조정해준다.
		if (d == 1) d = 3;
		else if (d == 3) d = 1;

		swap(x, y);

		board[x][y] = 1;
		for (int j = 0; j < gen[d][g].size(); j++) {
			switch (gen[d][g][j]) {
			case 0:
				y++;
				break;
			case 1:
				x++;
				break;
			case 2:
				y--;
				break;
			case 3:
				x--;
				break;
			default:
				break;
			}

			board[x][y] = 1;
		}
	}

	// (i, j)는 좌상단 좌표
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
				ans++;
		}
	}

	cout << ans;
}