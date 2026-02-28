#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> ones;

void bfs(int n, int m, vector<vector<int>> &v) {
	vector<vector<bool>> visited(n, vector<bool>(m));
	queue<pair<int, int>> q;
	int cnt = 0, max = 0;

	for (int i = 0;i < ones.size();i++) {
		if (!visited[ones[i].first][ones[i].second]) {
			q.push(ones[i]);
			visited[ones[i].first][ones[i].second] = true;

			int tmp = 1; // 각각의 넓이를 저장하는 변수
			cnt++;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;

				if (x - 1 >= 0 && v[x - 1][y] == 1 && visited[x - 1][y] == false) {
					q.push({ x - 1,y });
					visited[x - 1][y] = true;
					tmp++;
				}
				if (x + 1 < n && v[x + 1][y] == 1 && visited[x + 1][y] == false) {
					q.push({ x + 1,y });
					visited[x + 1][y] = true;
					tmp++;
				}
				if (y - 1 >= 0 && v[x][y - 1] == 1 && visited[x][y - 1] == false) {
					q.push({ x ,y - 1 });
					visited[x][y - 1] = true;
					tmp++;
				}
				if (y + 1 < m && v[x][y + 1] == 1 && visited[x][y + 1] == false) {
					q.push({ x ,y + 1 });
					visited[x][y + 1] = true;
					tmp++;
				}

				q.pop();
			}

			max = (tmp > max) ? tmp : max;
		}
	}

	cout << cnt << "\n" << max;

}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			
			v[i].push_back(x);

			if (x == 1)
				ones.push_back({ i,j });
		}
	}

	bfs(n, m, v);
}