#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(string a, string b, string c) {
	int x = 0, y = 0, z = 0;
	for (int i = 0;i < 4;i++) {
		if (a[i] != b[i])
			x++;
	}
	for (int i = 0;i < 4;i++) {
		if (b[i] != c[i])
			y++;
	}
	for (int i = 0;i < 4;i++) {
		if (c[i] != a[i])
			z++;
	}
	return x + y + z;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;

		vector<string> mbti;
		for (int j = 0;j < n;j++) {
			string s;
			cin >> s;
			mbti.push_back(s);
		}

		if (n > 32) {
			cout << 0 << "\n";
		}
		else {
			vector<vector<string>> com(n * (n - 1) * (n - 2) / 6);
			vector<int> tmp(n);
			for (int j = 0;j < 3;j++) {
				tmp[j] = 1;
			}

			int idx = 0;
			do {
				for (int j = 0; j < n; j++) {
					if (tmp[j] == 1)
						com[idx].push_back(mbti[j]);
				}
				idx++;
			} while (prev_permutation(tmp.begin(), tmp.end()));

			vector<int> cnt;
			for (int j = 0;j < com.size();j++) {
				cnt.push_back(calc(com[j][0], com[j][1], com[j][2]));
			}

			cout << *min_element(cnt.begin(), cnt.end()) << "\n";
		}
	}
}