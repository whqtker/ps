#include <iostream>

using namespace std;

int r, c, t;
int arr[50][50];
int dust[50][50];
int tmp[50][50];

// 미세먼지 확산
void spread() {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (dust[i][j]) {
				int spread_amount = arr[i][j] / 5;
				int spread_cnt = 0;

				for (int k = 0;k < 4;k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					// 확산이 되는 조건
					if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] != -1) {
						spread_cnt++;
						tmp[nx][ny] += spread_amount;
					}
				}

				if (spread_cnt != 0)
					tmp[i][j] -= spread_amount * spread_cnt;
			}
		}
	}

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			arr[i][j] += tmp[i][j];
			tmp[i][j] = 0;
		}
	}
}

void operate(int air) {
	// 위쪽 공기청정기
	for (int i = air - 2;i >= 0;i--) {
		if (arr[i + 1][0] == -1)
			continue;
		else
			arr[i + 1][0] = arr[i][0];
	}
	for (int i = 1;i < c;i++) {
		arr[0][i - 1] = arr[0][i];
	}
	for (int i = 1;i <= air - 1;i++) {
		arr[i - 1][c - 1] = arr[i][c - 1];
	}
	for (int i = c - 2;i >= 1;i--) {
		arr[air - 1][i + 1] = arr[air - 1][i];
		if (arr[air - 1][i - 1] == -1)
			arr[air - 1][i] = 0;
	}

	// 아랫쪽 공기청정기
	for (int i = air + 1;i < r;i++) {
		if (arr[i - 1][0] == -1)
			continue;
		else
			arr[i - 1][0] = arr[i][0];
	}
	for (int i = 1;i < c;i++) {
		arr[r - 1][i - 1] = arr[r - 1][i];
	}
	for (int i = r - 2;i >= air;i--) {
		arr[i + 1][c - 1] = arr[i][c - 1];
	}
	for (int i = c - 2;i >= 1;i--) {
		arr[air][i + 1] = arr[air][i];
		if (arr[air][i - 1] == -1)
			arr[air][i] = 0;
	}

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (arr[i][j] > 0)
				dust[i][j] = 1;
			else
				dust[i][j] = 0;
		}
	}
}

int main() {
	cin >> r >> c >> t;

	int air = 0; // 아랫쪽 공기청정기의 좌표, (air, 0)
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1)
				air = i;
			else if (arr[i][j] > 0)
				dust[i][j] = 1;
		}
	}

	for (int i = 0;i < t;i++) {
		spread();
		operate(air);
	}

	int ans = 0;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (arr[i][j] > 0)
				ans += arr[i][j];
		}
	}
	cout << ans;
}