#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t; // n: 구역의 수, m: 포탈의 수, t: 던전 제한 시간
int a[5001]; // 몬스터 기본 공격력
int x[5001]; // 몬스터 공격력/시간
int y[5001]; // 공격력 감소량/방어력
int c[5001]; // 코인
int dp[5001][101]; // dp[i][j]: j분에 i 구역에 있을 때 최대 코인의 수
vector<int> portal[5001]; // portal[i][j]: i에서 j로 이동하는 포탈 존재

void dp_clear() {
	for (int i = 0;i < 5001;i++) {
		for (int j = 0;j < 101;j++) {
			dp[i][j] = -1;
		}
	}
}

// 특정 방어력일 때 얻을 수 있는 최대 코인 수를 리턴, (남은 시간, 현재 구역 위치, 방어력)
int dungeon(int cur, int pos, long long armor) {
	// 남은 시간이 0이면 0 리턴
	if (cur == 0)
		return 0;

	// 전투에서 패배하면 0 리턴
	if (a[pos] + x[pos] * (t - cur) - y[pos] * armor > 0)
		return 0;

	// 동일한 구역, 시간의 dp가 이미 존재하는 경우 해당 값 리턴
	if (dp[pos][cur] != -1) {
		return dp[pos][cur];
	}

	int max_coin = c[pos]; // 최대 코인 수
	for (int i = 0;i < portal[pos].size();i++) {
		max_coin = max(dungeon(cur - 1, portal[pos][i], armor) + c[pos], max_coin);
	}

	dp[pos][cur] = max_coin;
	return max_coin;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> t;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> x[i] >> y[i] >> c[i];
	}
	for (int i = 1;i <= m;i++) {
		int p, q;
		cin >> p >> q;
		portal[p].push_back(q);
	}

	// 1번 구역에서 시작
	// 플레이어의 방어력이 충분히 크다고 가정하고 얻을 수 있는 최대 코인 수를 찾는다.
	// 그 다음 이분 탐색을 통해 최대 코인 수를 얻기 위한 최소 방어력을 찾는다.
	// 주어진 범위 내 가능한 방어력의 최댓값은 1e9+1e6이다. 즉, 방어력이 1e9+1e6이라면 어떠한 공격도 버틸 수 있다.
	dp_clear();
	long long armor = 1e9 + 1e6;
	int max_coin = dungeon(t, 1, armor); // 가능한 최대 코인 수

	long long l = 0;
	long long r = 1e9 + 1e6;
	long long mid = (l + r) / 2;

	while (l <= r) {
		dp_clear();
		mid = (l + r) / 2;
		if (dungeon(t, 1, mid) < max_coin) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l;
}