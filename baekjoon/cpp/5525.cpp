#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0;i < m;i++) {
		if (s[i] == 'I') {
			int p = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				p++;
				if (p == n) {
					p--;
					ans++;
				}
				i += 2;
			}
		}
	}
	cout << ans;
}