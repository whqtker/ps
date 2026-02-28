#include <iostream>
#include <string>

using namespace std;

int dp[101][101];

string pattern;
string s;

// dp의 초기값을 -1로 설정
void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			dp[i][j] = -1;
	}
}

// pattern의 pidx까지 문자열과 s의 sidx 문자열이 매칭되면 1, 그렇지 않으면 0 리턴
int solve(int pidx, int sidx) {
	// 두 문자열 모두 성공적으로 검사 완료
	if (pidx == pattern.length() && sidx == s.length())
		return 1;

	// s는 남았으나 매칭할 패턴이 없는 경우
	if (pidx >= pattern.length())
		return 0;

	// 현재 패턴의 문자가 *가 아닌데 s가 끝난 경우
	if (sidx >= s.length() && pattern[pidx] != '*')
		return 0;

	// 해당 인덱스의 dp값이 존재하는 경우
	if (dp[pidx][sidx] != -1)
		return dp[pidx][sidx];

	// 현재 패턴의 문자가 *인 경우
	if (pattern[pidx] == '*') {
		int result = 0;

		if (sidx <= s.length()) {
			// *와 매칭되는 문자가 0개인 경우
			if (solve(pidx + 1, sidx))
				result = 1;

			// *와 매칭되는 문자가 1개인 경우
			if (solve(pidx + 1, sidx + 1))
				result = 1;

			// *와 매칭되는 문자가 2개 이상인 경우
			if (solve(pidx, sidx + 1))
				result = 1;
		}

		return dp[pidx][sidx] = result;
	}
	else {
		if (pattern[pidx] == s[sidx])
			return dp[pidx][sidx] = solve(pidx + 1, sidx + 1);
		else
			return dp[pidx][sidx] = 0;
	}
}

int main() {
	cin >> pattern;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		init();
		cin >> s;

		if (solve(0, 0))
			cout << s << "\n";
	}
}