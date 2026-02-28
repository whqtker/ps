#include <iostream>
#include <algorithm>

#define INF 3276701

using namespace std;

int cumsum[101]; // cumsum[i]: i번째 원소까지 누적 합
int dp[101][51]; // dp[i][j]: 0부터 i-1까지의 배열 중 j개 구간 합의 최대값
int arr[100];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cumsum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + arr[i - 1];
    }

    // dp 초기화
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -INF;
        }
        // 선택한 구간이 0개인 경우
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(m, (i + 1) / 2); j++) {
            // i번째 원소를 선택하지 않는 경우
            dp[i][j] = dp[i - 1][j];

            // i번째 원소를 누적 합에 포함시키는 경우
            for (int k = 1; k <= i; k++) {
                // k번째부터 i번째까지 누적 합
                int k2i = cumsum[i] - cumsum[k - 1];

                // 첫 번째 구간인 경우
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], k2i);
                }
                else if (k >= 2) {
                    dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + k2i);
                }
            }
        }
    }

    cout << dp[n][m];
}
