#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	for (int i = 0;i < m;i++) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		pq.push(a + b);
		pq.push(a + b);
	}

	long long sum = 0;
	for (int i = 0;i < n;i++) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}