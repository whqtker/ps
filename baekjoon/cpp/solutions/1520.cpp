#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int arr[500][500];
int visited[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool outOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	priority_queue<tuple<int, int, int>> pq;
	pq.push({ arr[0][0],0,0 });
	visited[0][0] = 1;
	while (!pq.empty()) {
		int h = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = arr[nx][ny];

			if (!outOfBound(nx, ny) && h > nh) {
				if (!visited[nx][ny]) {
					pq.push({ nh,nx,ny });
					visited[nx][ny] += visited[x][y];
				}
				else
					visited[nx][ny] += visited[x][y];
			}
		}
	}

	cout << visited[n - 1][m - 1];
}