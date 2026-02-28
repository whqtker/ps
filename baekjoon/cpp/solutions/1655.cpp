#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	priority_queue<int> left; // 중앙값을 기준으로 왼쪽에 위치한 수
	priority_queue<int, vector<int>, greater<int>> right; // 중앙값을 기준으로 오른쪽에 위치한 수
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		// right에서 중앙값에 가까운 수(right.top())이 x보다 작으면 단순히 right에 x 삽입
		if (!right.empty() && right.top() < x)
			right.push(x);
		else
			left.push(x);

		int mid = i / 2 + 1;

		// left에 수가 치우친 경우
		if (left.size() > mid) {
			right.push(left.top());
			left.pop();
		}
		else if (left.size() < mid) {
			left.push(right.top());
			right.pop();
		}

		cout << left.top() << "\n";
	}
}