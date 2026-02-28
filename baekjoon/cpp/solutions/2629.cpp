#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int weight[30]; // 추의 무게
int dp[30][40001]; // dp[i][j]: i번째 구슬에 접근했을 때 가능한 최대 무게는 j

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> weight[i];
		dp[i][weight[i]] = 1;
	}


	for (int i = 1;i < n;i++) {
		for (int j = 1;j <= 40000;j++) {
			// 현재 추를 놓을 수 있다면
			if (weight[i] <= j) {
				// 현재 추를 놓아서 j를 만들 수 있다면
				if (dp[i - 1][j - weight[i]]) {
					dp[i][j] = 1;
				}
			}

			// j 무게가 이전에 만들어졌다면
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				dp[i][abs(j - weight[i])] = 1; // 구슬 쪽에 추를 놓는 경우
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;

		if (dp[n - 1][x])
			cout << "Y ";
		else
			cout << "N ";
	}
}