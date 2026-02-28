#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

bool outOfBound(int row, int col, int floor, int n, int m, int h) {
	// 범위 밖을 참조하면 true 리턴
	if (row < 0 || row >= m || col < 0 || col >= n || floor < 0 || floor >= h)
		return true;
	return false;
}

void bfs(vector<vector<int>> v, vector<int> x, vector<int> y, vector<int> z, int n, int m, int h) {
	vector <vector<int>> visited(m * h, vector<int>(n, -1));
	queue<tuple<int, int, int>> q;

	for (int i = 0;i < x.size();i++) {
		q.push({ x[i],y[i],z[i] });
		visited[m * z[i] + x[i]][y[i]] = 0;
	}

	while (!q.empty()) {
		int row = get<0>(q.front());
		int col = get<1>(q.front());
		int floor = get<2>(q.front());
		// 동서남북, 위아래로 방문 가능한 지점 탐색
		if (!outOfBound(row, col + 1, floor, n, m, h) && v[m * floor + row][col + 1] == 0 && visited[m * floor + row][col + 1] == -1) {
			q.push({ row,col + 1,floor });
			v[m * floor + row][col + 1] = 1;
			visited[m * floor + row][col + 1] = visited[m * floor + row][col] + 1;
		}
		if (!outOfBound(row, col - 1, floor, n, m, h) && v[m * floor + row][col - 1] == 0 && visited[m * floor + row][col - 1] == -1) {
			q.push({ row,col - 1,floor });
			v[m * floor + row][col - 1] = 1;
			visited[m * floor + row][col - 1] = visited[m * floor + row][col] + 1;
		}
		if (!outOfBound(row + 1, col, floor, n, m, h) && v[m * floor + row + 1][col] == 0 && visited[m * floor + row + 1][col] == -1) {
			q.push({ row + 1,col,floor });
			v[m * floor + row + 1][col] = 1;
			visited[m * floor + row + 1][col] = visited[m * floor + row][col] + 1;
		}
		if (!outOfBound(row - 1, col, floor, n, m, h) && v[m * floor + row - 1][col] == 0 && visited[m * floor + row - 1][col] == -1) {
			q.push({ row - 1,col,floor });
			v[m * floor + row - 1][col] = 1;
			visited[m * floor + row - 1][col] = visited[m * floor + row][col] + 1;
		}
		if (!outOfBound(row, col, floor + 1, n, m, h) && v[m * (floor + 1) + row][col] == 0 && visited[m * (floor + 1) + row][col] == -1) {
			q.push({ row,col,floor + 1 });
			v[m * (floor + 1) + row][col] = 1;
			visited[m * (floor + 1) + row][col] = visited[m * floor + row][col] + 1;
		}
		if (!outOfBound(row, col, floor - 1, n, m, h) && v[m * (floor - 1) + row][col] == 0 && visited[m * (floor - 1) + row][col] == -1) {
			q.push({ row,col,floor - 1 });
			v[m * (floor - 1) + row][col] = 1;
			visited[m * (floor - 1) + row][col] = visited[m * floor + row][col] + 1;
		}

		q.pop();
	}

	bool flag = false;
	for (int i = 0;i < m * h;i++) {
		if (find(v[i].begin(), v[i].end(), 0) != v[i].end()) {
			cout << -1;
			flag = true;
			break;
		}
	}

	if (flag == false) {
		int max_element = visited[0][0];
		for (int i = 0; i < visited.size(); i++) {
			for (int j = 0; j < visited[i].size(); j++) {
				if (visited[i][j] > max_element) {
					max_element = visited[i][j];
				}
			}
		}
		cout << max_element;
	}
}

int main() {
	int n, m, h;
	cin >> n >> m >> h; // n: 가로, m: 세로, h: 높이

	vector<vector<int>> v(m * h); // 토마토가 들어있는 상자
	vector<int> x; // 익은 토마토의 행
	vector<int> y; // 익은 토마토의 열
	vector<int> z; // 익은 토마토의 층
	for (int i = 0;i < m * h;i++) {
		for (int j = 0;j < n;j++) {
			int a;
			cin >> a;
			v[i].push_back(a);

			if (a == 1) {
				x.push_back(i % m);
				y.push_back(j);
				z.push_back(i / m);
			}
		}
	}

	bfs(v, x, y, z, n, m, h);
}