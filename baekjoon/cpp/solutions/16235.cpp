#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int food[11][11]; // 양분
int ground[11][11]; // 땅
vector<int> trees[11][11]; // trees[i][j]: (i, j)에 존재하는 나무들의 나이

void spring_summer(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trees[i][j].empty()) continue;

			sort(trees[i][j].begin(), trees[i][j].end());

			vector<int> tmp; // 살아남은 나무 임시 저장
			int nut = 0; // 죽은 나무의 양분 합

			for (int k = 0; k < trees[i][j].size(); k++) {
				if (ground[i][j] >= trees[i][j][k]) {
					ground[i][j] -= trees[i][j][k];
					tmp.push_back(trees[i][j][k] + 1);
				}
				else {
					nut += trees[i][j][k] / 2;
				}
			}

			trees[i][j] = tmp;
			ground[i][j] += nut;
		}
	}
}

void autumn(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trees[i][j].empty()) continue;

			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int x = i - 1; x <= i + 1; x++) {
						for (int y = j - 1; y <= j + 1; y++) {
							if (x == i && y == j) continue;
							if (x < 0 || y < 0 || x >= n || y >= n) continue;

							trees[x][y].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ground[i][j] += food[i][j];
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> food[i][j];
			ground[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}

	for (int i = 0; i < k; i++) {
		spring_summer(n);
		autumn(n);
		winter(n);
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += trees[i][j].size();
		}
	}

	cout << answer;
}