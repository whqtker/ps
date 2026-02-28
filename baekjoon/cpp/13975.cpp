#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pq.push(x);
		}

		long long ans = 0;
		while (pq.size() != 1) {
			long long x = pq.top();
			pq.pop();
			long long y = pq.top();
			pq.pop();
			ans += x + y;
			pq.push(x + y);
		}

		cout << ans << "\n";
	}
}