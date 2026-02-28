#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		cout << s[0] << s[s.size() - 1] << "\n";
	}
}
