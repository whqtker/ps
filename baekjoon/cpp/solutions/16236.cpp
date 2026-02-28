#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[20][20];
int visited[20][20];
int n;

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n;

	int sx, sy; // 상어의 위치
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	queue<tuple<int, int, int, int>> q; // {상어의 x좌표, 상어의 y좌표, 걸린 시간, 상어의 크기}
	q.push({ sx,sy,0,2 });

	int cnt = 0; // 먹은 물고기의 수
	while (!q.empty()) {
		clear();

		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int t = get<2>(q.front());
		int s = get<3>(q.front());
		q.pop();

		queue<tuple<int, int, int>> fish; // {물고기의 x좌표, 물고기의 y좌표, 걸린 시간}
		fish.push({ x,y,0 });
		visited[x][y] = 1;

		int d = 400; // 가장 가까운 물고기의 거리
		int w = 0; // 조건에 맞는 물고기의 무게
		int fX = 0; // 조건에 맞는 물고기의 x좌표
		int fY = 0; // 조건에 맞는 물고기의 y좌표
		bool flag = false; // 조건에 맞는 물고기가 존재하는지
		while (!fish.empty()) {
			int curX = get<0>(fish.front());
			int curY = get<1>(fish.front());
			int curT = get<2>(fish.front());
			fish.pop();

			for (int i = 0;i < 4;i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];

				if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
					// 빈 칸이거나 물고기의 무게가 같은 경우 지나갈 수 있음
					if (arr[nx][ny] == 0 || arr[nx][ny] == s) {
						visited[nx][ny] = 1;
						fish.push({ nx,ny,curT + 1 });
					}
					// 물고기가 있는 칸이며 상어의 무게보다 작은 경우
					else if (arr[nx][ny] > 0 && arr[nx][ny] < 7 && s > arr[nx][ny]) {
						flag = true;
						// 최단 거리인 경우
						if (curT + 1 < d) {
							d = curT + 1;
							w = arr[nx][ny];
							fX = nx;
							fY = ny;

							visited[nx][ny] = 1;
							fish.push({ nx,ny,curT + 1 });
						}
						// 거리가 같은 경우
						else if (curT + 1 == d) {
							// 현재 물고기가 더 위에 있는 경우
							if (fX > nx) {
								w = arr[nx][ny];
								fX = nx;
								fY = ny;

								visited[nx][ny] = 1;
								fish.push({ nx,ny,curT + 1 });
							}
							// 현재 물고기가 더 왼쪽에 있는 경우
							else if (fX == nx) {
								if (fY > ny) {
									w = arr[nx][ny];
									fX = nx;
									fY = ny;

									visited[nx][ny] = 1;
									fish.push({ nx,ny,curT + 1 });
								}
							}
						}
					}
				}
			}
		}

		// 먹을 수 있는 물고기가 없을 경우
		if (!flag) {
			cout << t;
			break;
		}

		// 물고기를 먹는다.
		arr[fX][fY] = 0;
		x = fX;
		y = fY;
		cnt++;
		// 상어가 자신의 크기와 같은 수의 물고기를 먹은 경우 크기가 1 증가
		if (cnt == s) {
			s++;
			cnt = 0;
		}
		t += d;
		q.push({ x,y,t,s });
	}
}