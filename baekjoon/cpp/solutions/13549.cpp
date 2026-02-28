#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int x = q.front();

		if (x == k)
			break;

		if (2 * x <= 100000 && visited[2 * x] == 0) {
			q.push(2 * x);
			visited[2 * x] = visited[x];
		}
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}

		q.pop();
	}

	cout << visited[k] - 1;
}