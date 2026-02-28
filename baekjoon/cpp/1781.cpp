#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	// 데드라인 순으로 정렬
	sort(v.begin(), v.end());

	// 처리 가능한 과제 저장
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int deadline = v[i].first;
		int cnt = v[i].second;
		pq.push(cnt);

		// 데드라인을 초과하는 경우 가장 개수가 작은 것을 버린다.
		// v[i]를 처리하기 위해서는 pq의 크기가 deadline보다 작거나 같아야 한다.
		if (pq.size() > deadline) {
			pq.pop();
		}
	}

	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}