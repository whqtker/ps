#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};

int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> gem;
	for (int i = 0;i < n;i++) {
		int m, v;
		cin >> m >> v;
		gem.push({ v,m }); // 가치, 무게
	}

	multiset<int> bag;
	for (int i = 0;i < k;i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	// 가격이 높은 보석부터 가방에 넣는다.
	// 들어갈 수 있는 가장 작은 가방에 들어가는 것이 좋다.
	long long ans = 0;
	while (!gem.empty()) {
		int m = gem.top().second;
		int v = gem.top().first;
		gem.pop();

		auto iter = bag.lower_bound(m);

		if (iter != bag.end()) {
			ans += v;
			bag.erase(iter);
		}
	}

	cout << ans;
}