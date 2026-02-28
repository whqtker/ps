#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n) {
		string s = to_string(n);
		for (int i = 0;i < s.length();i++) {
			if (s[i] == '1') {
				s.erase(i, 1);
				cnt++;
				i = -1;
			}
		}

		if (s == "")
			break;
		else 
			n = stoi(s);
		

		if (n) {
			n--;
			cnt++;
		}
	}

	cout << cnt;
}