#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector < pair<int, int>> v;
	for (int i = 0;i < n;i++) {
		int s, t;
		cin >> s >> t;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for (int i = 1;i < v.size();i++) {
		if (v[i].first >= pq.top()) {
			pq.pop();
			pq.push(v[i].second);
		}
		else
			pq.push(v[i].second);
	}

	cout << pq.size();
}