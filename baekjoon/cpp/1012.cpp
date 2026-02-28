#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int m, int n, vector<vector<int>> v, vector<vector<int>> visited, vector<pair<int, int>> coor) {
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0; i < coor.size(); i++) {
		if (visited[coor[i].first][coor[i].second] == 0) {
			q.push(coor[i]);

			while (!q.empty()) {
				// q.front()이 배추이고 방문을 안 했다면 동서남북 좌표를 큐에 넣는다.
				if (v[q.front().first][q.front().second] == 1 && visited[q.front().first][q.front().second] == 0) {
					visited[q.front().first][q.front().second] = 1;
					if (q.front().first != 0)
						q.push(make_pair(q.front().first - 1, q.front().second));
					if (q.front().second != 0)
						q.push(make_pair(q.front().first, q.front().second - 1));
					if (q.front().first != m - 1)
						q.push(make_pair(q.front().first + 1, q.front().second));
					if (q.front().second != n - 1)
						q.push(make_pair(q.front().first, q.front().second + 1));
					q.pop();
				}
				// 방문한 배추이거나 배추가 아니라면
				else {
					q.pop();
				}
			}
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, k; // m: 배추밭의 가로 길이, n: 배추밭의 세로 길이, k: 배추의 개수
		cin >> m >> n >> k;

		vector<vector<int>> v(m, vector<int>(n, 0)); // 배추밭
		vector<pair<int, int>> coor; // 배추가 있는 좌표
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y; // 배추의 좌표, x번 째 열, y번 째 행
			v[x][y] = 1;
			coor.push_back(make_pair(x, y));
		}

		vector<vector<int>> visited(m, vector<int>(n, 0)); // 방문을 안 했다면 0, 했다면 1
		cout << bfs(m, n, v, visited, coor) << "\n";
	}

}