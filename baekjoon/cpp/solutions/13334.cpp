#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v; // 좌표 저장
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		if (s > e)
			swap(s, e);

		v.push_back({ s,e });
	}

	// 끝점을 기준으로 정렬
	sort(v.begin(), v.end(), cmp);

	int d;
	cin >> d;

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq; // 시작점을 저장하는 우선순위 큐

	// 각 구간의 끝점에 철로를 설치한다.
	for (int i = 0; i < n; i++) {
		int e = v[i].second; // 철로의 끝점
		int s = e - d; // 철로의 시작점

		// 시작점 저장하기
		pq.push(v[i].first);

		// pq에 저장된 시작점이 s보다 작은 경우 제거
		while (!pq.empty()) {
			if (pq.top() < s)
				pq.pop();
			else
				break;
		}

		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}