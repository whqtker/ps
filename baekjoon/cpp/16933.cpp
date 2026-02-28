#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			v[i][j] = c;
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });

	// visited의 값이 홀수면 낮, 짝수면 밤이다. 즉 visited의 값이 홀수여야 벽을 부술 수 있다.
	vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1)));
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());

		int prev = visited[x][y][z];
		q.pop();

		bool flag = false; // 벽을 부술 수 있으나 밤인 경우 그대로 머무르는 것이 이득일 수 있다. 그러나 이 과정은 한 번만 수행되어야 함.

		if (x - 1 >= 0) {
			if (prev % 2 == 1 && v[x - 1][y] == '1' && z < k && !visited[x - 1][y][z + 1]) {
				q.push({ x - 1,y,z + 1 });
				visited[x - 1][y][z + 1] = prev + 1;
			}
			if (prev % 2 == 0 && v[x - 1][y] == '1' && z < k && !visited[x - 1][y][z + 1] && !flag) {
				q.push({ x,y,z });
				visited[x][y][z]++;
				flag = true;
			}

			if (v[x - 1][y] == '0' && !visited[x - 1][y][z]) {
				q.push({ x - 1,y,z });
				visited[x - 1][y][z] = prev + 1;
			}
		}
		if (x + 1 < n) {
			if (prev % 2 == 1 && v[x + 1][y] == '1' && z < k && !visited[x + 1][y][z + 1]) {
				q.push({ x + 1,y,z + 1 });
				visited[x + 1][y][z + 1] = prev + 1;
			}
			if (prev % 2 == 0 && v[x + 1][y] == '1' && z < k && !visited[x + 1][y][z + 1] && !flag) {
				q.push({ x,y,z });
				visited[x][y][z]++;
				flag = true;
			}

			if (v[x + 1][y] == '0' && !visited[x + 1][y][z]) {
				q.push({ x + 1,y,z });
				visited[x + 1][y][z] = prev + 1;
			}
		}
		if (y - 1 >= 0) {
			if (prev % 2 == 1 && v[x][y - 1] == '1' && z < k && !visited[x][y - 1][z + 1]) {
				q.push({ x ,y - 1,z + 1 });
				visited[x][y - 1][z + 1] = prev + 1;
			}
			if (prev % 2 == 0 && v[x][y - 1] == '1' && z < k && !visited[x][y - 1][z + 1] && !flag) {
				q.push({ x,y,z });
				visited[x][y][z]++;
				flag = true;
			}

			if (v[x][y - 1] == '0' && !visited[x][y - 1][z]) {
				q.push({ x ,y - 1,z });
				visited[x][y - 1][z] = prev + 1;
			}
		}
		if (y + 1 < m) {
			if (prev % 2 == 1 && v[x][y + 1] == '1' && z < k && !visited[x][y + 1][z + 1]) {
				q.push({ x ,y + 1,z + 1 });
				visited[x][y + 1][z + 1] = prev + 1;
			}
			if (prev % 2 == 0 && v[x][y + 1] == '1' && z < k && !visited[x][y + 1][z + 1] && !flag) {
				q.push({ x,y,z });
				visited[x][y][z]++;
				flag = true;
			}

			if (v[x][y + 1] == '0' && !visited[x][y + 1][z]) {
				q.push({ x,y + 1,z });
				visited[x][y + 1][z] = prev + 1;
			}
		}
	}
	int min = 1000001;
	for (int i = 0; i <= k; i++) {
		if (visited[n - 1][m - 1][i] != 0 && min > visited[n - 1][m - 1][i])
			min = visited[n - 1][m - 1][i];
	}

	if (min == 1000001)
		cout << -1;
	else
		cout << min;
}