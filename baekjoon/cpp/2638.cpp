#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[100][100];
int visited[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		// 외부 공기 찾기
		clear();
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		visited[0][0] = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && arr[nx][ny] != 1) {
					visited[nx][ny] = 1;
					arr[nx][ny] = 2; // 외부 공기는 2로 구분
					q.push({ nx,ny });
				}
			}
		}


		// 조건에 맞는 치즈 찾기
		clear();
		vector<pair<int, int>> melt; // 조건에 맞는 치즈 좌표
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					q.push({ i, j });
					visited[i][j] = 1;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						int flag = 0;
						for (int i = 0;i < 4;i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];

							if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 2) {
								flag++;
							}
							else if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && arr[nx][ny] == 1) {
								visited[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}

						if (flag >= 2)
							melt.push_back({ x,y });
					}
				}
			}
		}

		// 치즈 녹이기
		if (melt.empty())
			break;

		for (int i = 0;i < melt.size();i++) {
			int x = melt[i].first;
			int y = melt[i].second;
			arr[x][y] = 0;
		}

		cnt++;
	}

	cout << cnt;
}