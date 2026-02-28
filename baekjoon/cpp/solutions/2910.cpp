#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second > y.second;
}

int main() {
	int n, c;
	cin >> n >> c;

	vector<pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		bool flag = false;
		for (int j = 0;j < v.size();j++) {
			if (v[j].first == x) {
				v[j].second++;
				flag = true;
			}
		}

		if (flag == false)
			v.push_back({ x,1 });
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0;i < v.size();i++) {
		for (int j = 0;j < v[i].second;j++) {
			cout << v[i].first << " ";
		}
	}
}