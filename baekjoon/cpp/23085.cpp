#include <iostream>
#include <queue>
#include <string>

using namespace std;

int visited[3001];
int n, m;
string s;

int main() {
	cin >> n >> m >> s;

	int head = 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == 'H')
			head++;
	}

	queue<pair<int, int>> q;
	q.push({ head, 0 });
	visited[head] = 1;
	while (!q.empty()) {
		int h = q.front().first;
		int t = n - h;
		int cnt = q.front().second;
		q.pop();

		if (t == n) {
			cout << cnt;
			return 0;
		}

		// 'H'인 동전을 뒤집을 개수
		for (int i = 1;i <= m;i++) {
			if (i <= h && m - i <= t) {
				if (!visited[h - 2 * i + m]) {
					visited[h - 2 * i + m] = 1;
					q.push({ h - 2 * i + m ,cnt + 1 });
				}
			}
		}
	}

	cout << -1;
}