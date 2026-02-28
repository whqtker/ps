#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int n,vector<int> stair) {
	vector<vector<int>> v(n, vector<int>(3)); // v[i][j]: j개의 계단을 연속해서 밟고 i번 째 계단을 밟았을 때 점수의 최댓값, j = 1 or j = 2, j = 3은 불가능.

	// 초기값 설정(첫 번째, 두 번째 계단)
	v[0][1] = stair[0];
	v[0][2] = 0;
	if (n > 1) {
		v[1][1] = stair[1];
		v[1][2] = stair[0] + stair[1];
	}

	for (int i = 2; i < n; i++) {
		// 만약 밟은 계단이 1개의 계단을 연속해서 밟은 경우 i - 2번째 계단은 반드시 밟았어야 한다. 따라서 i - 2번 째 계단의 점수에 i번 째 계단의 점수를 더한다.
		// i - 2번 째 계단의 점수는 그 계단까지 연속해서 한 번 밟은 경우, 두 번 밟은 경우가 있다. 따라서 그들의 최댓값을 가져와야 한다.
		v[i][1] = max(v[i - 2][1], v[i - 2][2]) + stair[i];

		// 밟은 계단이 2개의 계단을 연속해서 밟은 경우 i - 1번째 계단은 반드시 밟았어야 한다. 그러나 i - 1번 째 계단을 밟았을 때 연속해서 두 개를 밟았다면 i번 째 계단을 밟을 수 없다.
		// 따라서 i - 1번 째 계단의 연속해서 한 번 밟은 경우에 i번 째 계단의 점수를 더한다.
		v[i][2] = v[i - 1][1] + stair[i];
	}

	return max(v[n - 1][1], v[n - 1][2]);
}

int main() {
	int n;
	cin >> n;

	vector<int> stair; // 계단에 쓰여 있는 점수
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		stair.push_back(x);
	}

	cout << dp(n,stair);
}