#include <iostream>

#define INF 2001

using namespace std;

int dp[1001][1001]; // dp[i][j]: (i, j)에 도달하기까지 부순 감시카메라의 최소 개수
int psum_row[1001][1001]; // 행 방향 누적 합
int psum_col[1001][1001]; // 열 방향 누적 합
int n, m, k;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> k;

	// 영역의 첫 번째 행, 열에 대하여 2차원 imos법 사용
	// 기준점을 찍고 쉬프팅
	for (int i = 0;i < k;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// 1. 첫 번째 행, 열에 대하여 기준점 찍기
		psum_row[a][b]++;
		psum_row[a + 1][b]--;
		psum_row[a][d + 1]--;
		psum_row[a + 1][d + 1]++;

		psum_col[a][b]++;
		psum_col[a][b + 1]--;
		psum_col[c + 1][b]--;
		psum_col[c + 1][b + 1]++;
	}

	// 2. 기준점 쉬프팅
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			psum_row[i][j] += psum_row[i][j - 1];
			psum_col[i][j] += psum_col[i][j - 1];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			psum_row[i][j] += psum_row[i - 1][j];
			psum_col[i][j] += psum_col[i - 1][j];
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dp[i][j] = INF;
		}
	}

	dp[1][1] = psum_row[1][1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (i > 1)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + psum_row[i][j]);
			if (j > 1)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + psum_col[i][j]);
		}
	}

	cout << dp[n][m];
}
