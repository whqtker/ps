#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int visited[1000][1000];
int cluster[1000][1000];
int cluster_visited[1000][1000];
int cluster_num[1000][1000];

bool outOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	vector<string> board;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0,1,0,-1 };
	int num = 1; // 클러스터 번호

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '0' && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				int cnt = 1;

				// 이동할 수 있는 곳의 최댓값 구하기
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (!outOfBound(nx, ny) && !visited[nx][ny] && board[nx][ny] == '0') {
							cnt++;
							visited[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}

				q.push({ i,j });
				cluster_visited[i][j] = 1;
				cluster[i][j] = cnt;
				cluster_num[i][j] = num;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (!outOfBound(nx, ny) && !cluster_visited[nx][ny] && board[nx][ny] == '0') {
							cluster_visited[nx][ny] = 1;
							cluster_num[nx][ny] = num;
							cluster[nx][ny] = cnt;
							q.push({ nx,ny });
						}
					}
				}

				num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '1') {
				int ans = 1;
				vector<int> num_visited;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!outOfBound(nx, ny) && board[nx][ny] == '0' && find(num_visited.begin(), num_visited.end(), cluster_num[nx][ny]) == num_visited.end()) {
						ans += cluster[nx][ny];
						num_visited.push_back(cluster_num[nx][ny]);
					}
				}
				cout << ans % 10;
			}
			else
				cout << 0;
		}
		cout << "\n";
	}
}