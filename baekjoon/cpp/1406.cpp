#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s;
	cin >> s;
	int n;
	cin >> n;

	stack<char> cur, tmp;
	for (int i = 0;i < s.size();i++)
		cur.push(s[i]);

	for (int i = 0;i < n;i++) {
		char c;
		cin >> c;

		if (c == 'L') {
			if (!cur.empty()) {
				tmp.push(cur.top());
				cur.pop();
			}
		}
		if (c == 'D') {
			if (!tmp.empty()) {
				cur.push(tmp.top());
				tmp.pop();
			}
		}
		if (c == 'B') {
			if (!cur.empty())
				cur.pop();
		}
		if (c == 'P') {
			char a;
			cin >> a;
			cur.push(a);
		}
	}

	while (!cur.empty()) {
		tmp.push(cur.top());
		cur.pop();
	}

	while (!tmp.empty()) {
		cout << tmp.top();
		tmp.pop();
	}
}