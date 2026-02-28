#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	int t;
	queue<int> q;
	while (1) {
		cin >> t;
		if (t == -1)
			break;

		if (t == 0)
			q.pop();
		else {
			if (q.size() < n)
				q.push(t);
		}
	}

	if (q.empty())
		cout << "empty";
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}
}