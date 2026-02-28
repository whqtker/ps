#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 16000001

using namespace std;
int n;
int w[16][16];
int dp[16][1 << 16]; // 방문 여부를 비트마스킹을 통해 구현

// n = 4, visited == 0010 이면 두 번째 마을만 방문, visited == 1111이면 모든 마을 방문
int dfs(int cur, int visited) {
	// 모든 마을 방문
	if (visited == (1 << n) - 1) {
		// 이동할 수 없는 경우
		if (w[cur][0] == 0)
			return INF;
		return w[cur][0];
	}

	// 현재 마을을 방문한 경우
	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	// 현재 마을 초기화
	dp[cur][visited] = INF;

	for (int i = 0;i < n;i++) {
		// 연결되지 않았다면 pass
		if (w[cur][i] == 0)
			continue;

		// 이미 방문했다면 pass
		if ((visited & (1 << i)) == (1 << i))
			continue;

		dp[cur][visited] = min(dp[cur][visited], w[cur][i] + dfs(i, visited | 1 << i));
	}

	return dp[cur][visited];
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> w[i][j];
		}
	}

	// -1로 초기화(방문 여부와 연결되지 않은 도시 구분)
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);
}