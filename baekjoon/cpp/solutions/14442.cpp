#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> v;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });

	vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1)));
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front()); // 벽을 부순 적이 있는지

		if (x - 1 >= 0) {
			if (v[x - 1][y] == '0' && !visited[x - 1][y][z]) {
				q.push({ x - 1,y,z });
				visited[x - 1][y][z] = visited[x][y][z] + 1;
			}
			else if (v[x - 1][y] == '1' && z < k && visited[x - 1][y][z + 1] == 0) {
				q.push({ x - 1,y,z + 1 });
				visited[x - 1][y][z + 1] = visited[x][y][z] + 1;
			}
		}
		if (x + 1 < n) {
			if (v[x + 1][y] == '0' && !visited[x + 1][y][z]) {
				q.push({ x + 1,y ,z });
				visited[x + 1][y][z] = visited[x][y][z] + 1;
			}
			else if (v[x + 1][y] == '1' && z < k && visited[x + 1][y][z + 1] == 0) {
				q.push({ x + 1,y,z + 1 });
				visited[x + 1][y][z + 1] = visited[x][y][z] + 1;
			}
		}
		if (y - 1 >= 0) {
			if (v[x][y - 1] == '0' && !visited[x][y - 1][z]) {
				q.push({ x ,y - 1 ,z });
				visited[x][y - 1][z] = visited[x][y][z] + 1;
			}
			else if (v[x][y - 1] == '1' && z < k && visited[x][y - 1][z + 1] == 0) {
				q.push({ x ,y - 1,z + 1 });
				visited[x][y - 1][z + 1] = visited[x][y][z] + 1;
			}
		}
		if (y + 1 < m) {
			if (v[x][y + 1] == '0' && !visited[x][y + 1][z]) {
				q.push({ x ,y + 1 ,z });
				visited[x][y + 1][z] = visited[x][y][z] + 1;
			}
			else if (v[x][y + 1] == '1' && z < k && visited[x][y + 1][z + 1] == 0) {
				q.push({ x ,y + 1,z + 1 });
				visited[x][y + 1][z + 1] = visited[x][y][z] + 1;
			}
		}

		q.pop();
	}

	int ans = -1;
	for (int i = 0;i <= k;i++) {
		if (visited[n - 1][m - 1][i] != 0) {
			if (ans == -1)
				ans = visited[n - 1][m - 1][i];
			else
				ans = min(ans, visited[n - 1][m - 1][i]);
		}
	}

	cout << ans;
}