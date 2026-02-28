#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int x = 0, y = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
				x += a[i] - '0';
		}

		for (int i = 0; i < b.size(); i++) {
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9)
				y += b[i] - '0';
		}

		if (x != y)
			return x < y;
		else
			return a < b;
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}