#include <iostream>
#include <algorithm>

using namespace std;

string arr[1001];
int dp[1001][1001]; // dp[i][j]: 정사각형의 우하단 좌표가 (i, j)라고 할 때 최대 변 길이

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		string x;
		cin >> x;
		arr[i] = " " + x;
		for (int j = 1;j <= m;j++)
			dp[i][j] = arr[i][j] - '0';
	}

	int max = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (arr[i][j] == '1') {
				dp[i][j] = min({ dp[i - 1][j],dp[i - 1][j - 1],dp[i][j - 1] }) + 1;
			}
			max = (dp[i][j] > max) ? dp[i][j] : max;
		}
	}

	cout << max * max;
}