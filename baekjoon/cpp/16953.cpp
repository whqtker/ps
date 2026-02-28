#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	queue<pair<long long,int>> q;
	q.push({ a,1 });

	while (!q.empty()) {
		long long x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == b) {
			cout << cnt;
			return 0;
		}

		if (2 * x <= b ) {
			q.push({ 2 * x,cnt + 1 });
		}
		if (10 * x + 1 <= b ) {
			q.push({ 10 * x + 1,cnt + 1 });
		}
	}

	cout << -1;
}