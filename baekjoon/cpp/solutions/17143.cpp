#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int R, C, M;
vector<tuple<int, int, int, int>> shark[100][100];

void move() {
	vector<tuple<int, int, int, int>> tmp[100][100];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < shark[i][j].size(); k++) {
				// 잡히거나 먹히지 않은 상어에 대하여 이동
				if (!get<3>(shark[i][j][k])) {
					int s = get<0>(shark[i][j][k]);
					int d = get<1>(shark[i][j][k]);
					int z = get<2>(shark[i][j][k]);

					int cnt = 0; // 상어가 움직인 횟수

					// 상하
					if (d == 1 || d == 2) {
						int n = i; // 움직인 상어의 좌표

						while (cnt < s) {
							cnt++;

							if (d == 1)
								n--;
							else if (d == 2)
								n++;

							if (n < 0) {
								d = 2;
								n = 1;
							}
							else if (n >= R) {
								d = 1;
								n = R - 2;
							}
						}
						tmp[n][j].push_back({ s,d,z,0 });
					}

					// 좌우
					else if (d == 3 || d == 4) {
						int n = j; // 움직인 상어의 좌표

						while (cnt < s) {
							cnt++;

							if (d == 3)
								n++;
							else if (d == 4)
								n--;

							if (n < 0) {
								d = 3;
								n = 1;
							}
							else if (n >= C) {
								d = 4;
								n = C - 2;
							}
						}
						tmp[i][n].push_back({ s,d,z,0 });
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			shark[i][j] = tmp[i][j];
		}
	}
}

int fishing(int col) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < shark[i][col].size(); j++) {
			// 잡히거나 먹히지 않았다면
			if (!get<3>(shark[i][col][j])) {
				get<3>(shark[i][col][j]) = 1;
				return get<2>(shark[i][col][j]);
			}
		}
	}

	return 0;
}

void eat() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int maxSize = 0;
			for (int k = 0; k < shark[i][j].size(); k++) {
				// 잡히거나 먹히지 않은 상어에 대하여
				if (!get<3>(shark[i][j][k])) {
					int z = get<2>(shark[i][j][k]);

					maxSize = max(maxSize, z);
				}
			}

			for (int k = 0; k < shark[i][j].size(); k++) {
				if (!get<3>(shark[i][j][k])) {
					int z = get<2>(shark[i][j][k]);

					if (maxSize > z)
						get<3>(shark[i][j][k]) = 1;
				}
			}
		}
	}
}

int action(int col) {
	int ret = fishing(col);
	move();
	eat();

	return ret;
}

int main() {
	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;

		if (d == 1 || d == 2)
			s %= (R - 1) * 2;
		else if (d == 3 || d == 4)
			s %= (C - 1) * 2;

		// 상어 존재 여부 추가
		shark[r - 1][c - 1].push_back({ s,d,z,0 });
	}

	int ans = 0;
	for (int i = 0; i < C; i++) {
		ans += action(i);
	}

	cout << ans;
}