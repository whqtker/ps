#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int weight[1000001]; // 바나나의 무게
int dp[1000001];
int route[1000001]; // 경로 역추적
// route[i]: i보다 작거나 같은 바나나 중 가장 가까운 바나나 묶음의 첫 번째 바나나 인덱스

int main() {
	int n, k, c; // 바나나의 수, 한 번에 들고갈 수 있는 수, 걸리는 시간
	cin >> n >> k >> c;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i < k) {
			dp[i] = dp[i - 1] + weight[i];
		}
		else {
			int case1 = dp[i - k] + c; // 현재 바나나를 묶는다면
			int case2 = weight[i] + dp[i - 1]; // 현재 바나나 하나만 들고 간다면

			if (case1 < case2) {
				dp[i] = case1;
				route[i] = i - k + 1;
			}
			else {
				dp[i] = case2;
				route[i] = route[i - 1];
			}
		}
	}

	cout << dp[n] << "\n";

	stack<int> s;
	int idx = n;
	int cnt = 0;
	while (route[idx] > 0) {
		cnt++;
		s.push(route[idx]);
		idx = route[idx] - 1;
	}

	cout << cnt << "\n";

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}