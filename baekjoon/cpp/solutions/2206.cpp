#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> v;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });

	vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2)));
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
			else if (v[x - 1][y] == '1' && !z) {
				q.push({ x - 1,y,1 });
				visited[x - 1][y][1] = visited[x][y][0] + 1;
			}
		}
		if (x + 1 < n) {
			if (v[x + 1][y] == '0' && !visited[x + 1][y][z]) {
				q.push({ x + 1,y ,z });
				visited[x + 1][y][z] = visited[x][y][z] + 1;
			}
			else if (v[x + 1][y] == '1' && !z) {
				q.push({ x + 1,y,1 });
				visited[x + 1][y][1] = visited[x][y][0] + 1;
			}
		}
		if (y - 1 >= 0) {
			if (v[x][y - 1] == '0' && !visited[x][y - 1][z]) {
				q.push({ x ,y - 1 ,z });
				visited[x][y - 1][z] = visited[x][y][z] + 1;
			}
			else if (v[x][y - 1] == '1' && !z) {
				q.push({ x ,y - 1,1 });
				visited[x][y - 1][1] = visited[x][y][0] + 1;
			}
		}
		if (y + 1 < m) {
			if (v[x][y + 1] == '0' && !visited[x][y + 1][z]) {
				q.push({ x ,y + 1 ,z });
				visited[x][y + 1][z] = visited[x][y][z] + 1;
			}
			else if (v[x][y + 1] == '1' && !z) {
				q.push({ x ,y + 1,1 });
				visited[x][y + 1][1] = visited[x][y][0] + 1;
			}
		}

		q.pop();
	}

	if (visited[n - 1][m - 1][0] == 0 && visited[n - 1][m - 1][1] == 0)
		cout << -1;
	else if (visited[n - 1][m - 1][0] == 0)
		cout << visited[n - 1][m - 1][1];
	else if (visited[n - 1][m - 1][1] == 0)
		cout << visited[n - 1][m - 1][0];
	else
		cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
}