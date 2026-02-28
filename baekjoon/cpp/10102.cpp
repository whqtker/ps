#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<char> v;
	for (int i = 0; i < n; i++) {
		char s;
		cin >> s;
		v.push_back(s);
	}

	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 'A') a++;
		else if (v[i] == 'B') b++;
	}

	if (a > b) cout << "A";
	else if (a < b) cout << "B";
	else cout << "Tie";
}