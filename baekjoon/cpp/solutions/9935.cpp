#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string str, bomb;
	cin >> str >> bomb;
	int len = bomb.size();

	stack<char> s;

	for (int i = 0;i < str.size();i++) {
		s.push(str[i]);

		if (str[i] == bomb[len - 1] && s.size() >= len) {
			string tmp;
			for (int j = 0;j < len;j++) {
				tmp.push_back(s.top());
				s.pop();
			}

			reverse(tmp.begin(), tmp.end());
			if (tmp != bomb) {
				for (int j = 0;j < len;j++)
					s.push(tmp[j]);
			}
		}
	}

	string ans;
	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	reverse(ans.begin(), ans.end());

	if (ans.length() == 0)
		cout << "FRULA";
	else {
		cout << ans;
	}
}