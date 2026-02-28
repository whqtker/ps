#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {
		vector<pair<int, int>> v;
		for (int j = 0;j < 4;j++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());

		vector<pair<int, int>> idx = { {0,1},{0,2},{2, 3},{1,3} };
		bool isSameLen = true;
		for (int j = 0;j < 4;j++) {
			if (pow(v[idx[j].first].first - v[idx[j].second].first, 2) + pow(v[idx[j].first].second - v[idx[j].second].second, 2) != pow(v[idx[(j + 1) % 4].first].first - v[idx[(j + 1) % 4].second].first, 2) + pow(v[idx[(j + 1) % 4].first].second - v[idx[(j + 1) % 4].second].second, 2))
				isSameLen = false;
		}

		bool isOrtho = true;
		for (int j = 0;j < 4;j++) {
			if ((v[idx[j].first].first - v[idx[j].second].first) * (v[idx[(j + 1) % 4].first].first - v[idx[(j + 1) % 4].second].first) + (v[idx[j].first].second - v[idx[j].second].second) * (v[idx[(j + 1) % 4].first].second - v[idx[(j + 1) % 4].second].second) != 0)
				isOrtho = false;
		}

		if (isSameLen && isOrtho)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}