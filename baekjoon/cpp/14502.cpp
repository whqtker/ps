#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8][8];

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> wall; // 빈 공간 벡터(벽이 설치될 공간의 후보)
	vector<pair<int, int>> virus;
	int _wall = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0)
				wall.push_back({ i,j });
			else if (arr[i][j] == 1)
				_wall++;
			else if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int ans = 0; // 전체 영역 - 바이러스의 총합 - 벽의 수 - 3(설치된 벽의 수)

	for (int i = 0; i < wall.size(); i++) {
		for (int j = i + 1; j < wall.size(); j++) {
			for (int k = j + 1; k < wall.size(); k++) {
				int visited[8][8] = {};
				queue<pair<int, int>> q;

				int cnt = virus.size(); // 퍼진 바이러스의 총합
				for (int l = 0; l < virus.size(); l++) {
					q.push({ virus[l].first,virus[l].second });
					visited[virus[l].first][virus[l].second] = 1;
				}

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int idx = 0; idx < 4; idx++) {
						int nx = x + dx[idx];
						int ny = y + dy[idx];
						// 새로 설치된 벽에는 접근하면 안됨
						bool flag = (nx == wall[i].first && ny == wall[i].second) || (nx == wall[j].first && ny == wall[j].second) || (nx == wall[k].first && ny == wall[k].second);

						if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && arr[nx][ny] == 0 && !flag) {
							visited[nx][ny] = 1;
							cnt++;
							q.push({ nx,ny });
						}
					}
				}
				ans = max(ans, n * m - cnt - _wall - 3);
			}
		}
	}

	cout << ans;
}