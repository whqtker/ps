#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int> pq;
	int my;
	cin >> my;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int cnt = 0;
	while (pq.top() >= my) {
		int x = pq.top();
		pq.pop();
		pq.push(x - 1);
		my++;
		cnt++;
	}
	cout << cnt;
}