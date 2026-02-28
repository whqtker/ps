#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ladder[101];
int snake[101];
int visited[101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		snake[x] = y;
	}

	queue<pair<int,int>> q;
	q.push({ 1,0 });
	visited[1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int n = q.front().second;
		q.pop();

		if (x == 100) {
			cout << n;
			return 0;
		}

		for (int i = 1;i <= 6;i++) {
			if (x + i <= 100 && !visited[x + i]) {
				visited[x + i] = 1;
				if (ladder[x + i] != 0) {
					q.push({ ladder[x + i],n + 1 });
					visited[ladder[x + i]] = 1;
				}
				else if (snake[x + i] != 0) {
					q.push({ snake[x + i],n + 1 });
					visited[snake[x + i]] = 1;
				}
				else {
					q.push({ x + i,n + 1 });
				}
			}
		}
	}
}