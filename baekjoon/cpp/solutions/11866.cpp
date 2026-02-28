#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;

	// 1부터 n까지 enqueue
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	// k번 pop()을 하고, 마지막 pop()을 제외한 나머지는 다시 euqueue
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (!q.empty()) cout << ", ";
	}
	cout << ">";
}