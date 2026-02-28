#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int> dp(str.length());
	if (str[0] == '0') cout << 0;
	else {
		dp[0] = 1;
		// 10, 20을 제외하고 10 <= str <= 26에 해당하는 수는 2가지
		if (str.length() > 1) {
			int second = stoi(str.substr(0, 2));
			if (10 <= second && second <= 26) {
				if (str[1] == '0') dp[1] = 1;
				else dp[1] = 2;
			}
			else dp[1] = 1;

			for (int i = 2;i < str.length();i++) {
				int sub = stoi(str.substr(i - 1, 2));
				if (10 <= sub && sub <= 26) {
					if (str[i] == '0') {
						if (i % 2 == 1)dp[i] = dp[i - 1]; // 2020
						else dp[i] = dp[i - 1] - 1; // 210
					}
					else dp[i] = dp[i - 1] + dp[i - 2]; // 2421
				}
				else dp[i] = dp[i - 1]; // 2459
			}
		}
		cout << dp[str.length() - 1];
	}
}