#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	map<int, int> mp;
	int score = 0;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'O')
				mp[p] += v[j];
		}
		score = max(mp[p], score);
	}

	for (auto iter : mp) {
		if (iter.second == score) {
			cout << iter.first << " " << score;
			break;
		}
	}
}