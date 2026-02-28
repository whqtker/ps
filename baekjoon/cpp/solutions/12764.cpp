#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

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

	sort(v.begin(), v.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> com; // {종료 시간, 컴퓨터 번호}
	priority_queue<int, vector<int>, greater<int>> able; // 가능한 컴퓨터 번호

	int total = 0; // 사용한 총 컴퓨터
	vector<int> cnt(n); // 컴퓨터 사용 횟수
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;

		// 사용자 시작 시간보다 컴퓨터 종료 시간이 빠른 경우 제거
		while (!com.empty() && com.top().first < start) {
			int num = com.top().second;
			com.pop();
			able.push(num);
		}

		// 컴퓨터 배정
		if (able.empty()) {
			cnt[total]++;
			com.push({ end,total });
			total++;
		}
		else {
			cnt[able.top()]++;
			com.push({ end,able.top() });
			able.pop();
		}
	}

	cout << total << "\n";
	for (int i = 0; i < total; i++) {
		cout << cnt[i] << " ";
	}
}