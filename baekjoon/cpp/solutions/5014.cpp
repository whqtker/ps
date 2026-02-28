#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1000001]; // 버튼을 누르는 최소 횟수 저장

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int n = q.front();

		if (n + u <= f && visited[n + u] == 0 && u != 0) {
			q.push(n + u);
			visited[n + u] = visited[n] + 1;
		}
		if (n - d > 0 && visited[n - d] == 0 && d != 0) {
			q.push(n - d);
			visited[n - d] = visited[n] + 1;
		}
		q.pop();
	}

	if (visited[g] == 0)
		cout << "use the stairs";
	else
		cout << visited[g];
}