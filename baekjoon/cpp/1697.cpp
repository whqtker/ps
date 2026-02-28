#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void bfs(int n, int k) {
	vector<int> visited(200001);
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	int cnt = 0;
	while (q.front() != k) {
		int x = q.front();
		if (x + 1 <= 100001 && visited[x + 1] == 0) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		if (x - 1 >= 0) {
			if (visited[x - 1] == 0) {
				q.push(x - 1);
				visited[x - 1] = visited[x] + 1;

			}
		}
		if (2 * x <= 200000 && visited[2 * x] == 0) {
			q.push(2 * x);
			visited[2 * x] = visited[x] + 1;
		}
		q.pop();
	}

	cout << visited[k] - 1;
}

int main() {
	int n, k;
	cin >> n >> k;

	bfs(n, k);
}