#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;

		priority_queue<int> desc;
		priority_queue<int, vector<int>, greater<int>> asc;
		map<int, int> m;

		for (int j = 0;j < n;j++) {
			char c;
			cin >> c;
			if (c == 'I') {
				int x;
				cin >> x;
				desc.push(x);
				asc.push(x);
				m[x]++;
			}
			else if (c == 'D') {
				int x;
				cin >> x;

				if (x == 1) {
					if (!desc.empty()) {
						m[desc.top()]--;
						desc.pop();
					}
				}
				else if (x == -1) {
					if (!asc.empty()) {
						m[asc.top()]--;
						asc.pop();
					}
				}
			}

			while (!desc.empty() && m[desc.top()] == 0)
				desc.pop();
			while (!asc.empty() && m[asc.top()] == 0)
				asc.pop();
		}
		if (desc.empty() || asc.empty())
			cout << "EMPTY\n";
		else {
			cout << desc.top() << " " << asc.top() << "\n";
		}
	}
}