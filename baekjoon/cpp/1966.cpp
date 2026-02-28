#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m; // n개의 문서, m번 째 문서를 찾고 싶음(맨 왼쪽은 0번 째)
		cin >> n >> m;

		queue<pair<int, int>> q; // 프린터 큐, pair은 인덱스, 중요도이다.
		vector<int> v; // 중요도를 저장하는 벡터
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			v.push_back(x);
			q.push(pair<int, int>(j, x));
		}

		sort(v.rbegin(), v.rend());
		int max = v[0]; // 가장 큰 중요도
		int cnt = 0; // 인쇄된 문서의 수
		while (1) {
			// q.front()의 중요도가 가장 크고 찾고자 하는 인덱스라면 인쇄한다.
			if (q.front().second == max && q.front().first == m) {
				cout << cnt + 1 << "\n";
				break;
			}
			// q.front()의 중요도가 가장 크다면 인쇄한다.
			else if (q.front().second == max) {
				q.pop();
				cnt++;

				// 최댓값 갱신
				v.erase(v.begin());
				max = v[0];
			}
			else {
				q.push(q.front());
				q.pop();
			}

		}
	}
}