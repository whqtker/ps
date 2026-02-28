#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string num;
	cin >> num;

	stack<char> s;

	for (char c : num) {
		if (s.empty()) {
			s.push(c);
			continue;
		}

		while (!s.empty() && c > s.top() && k > 0) {
			s.pop();
			k--;
		}
		s.push(c);
	}

	while (k > 0) {
		s.pop();
		k--;
	}

	string ans = "";
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
}