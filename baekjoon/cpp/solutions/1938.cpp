#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char arr[52][52]; // padding
int visited[52][52][2]; // visited[i][j][d]: { i, j }를 방문함. 방향은 d

struct Log {
	int x; // 통나무 가운데 x 좌표
	int y; // 통나무 가운데 y 좌표
	bool dir; // false: 세로, true: 가로
};

bool check(int x, int y, int i, bool dir) {
	switch (i) {
		// 상
	case 0:
		// 가로
		if (dir)
			return arr[x][y - 1] != '1' && arr[x][y] != '1' && arr[x][y + 1] != '1';
		else
			return arr[x - 1][y] != '1';
	case 1:
		if (dir)
			return arr[x][y + 1] != '1';
		else
			return arr[x - 1][y] != '1' && arr[x][y] != '1' && arr[x + 1][y] != '1';
	case 2:
		if (dir)
			return arr[x][y - 1] != '1' && arr[x][y] != '1' && arr[x][y + 1] != '1';
		else
			return arr[x + 1][y] != '1';
	case 3:
		if (dir)
			return arr[x][y - 1] != '1';
		else
			return arr[x - 1][y] != '1' && arr[x][y] != '1' && arr[x + 1][y] != '1';
	default:
		break;
	}
}

bool rotate_check(int x, int y) {
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (arr[i][j] == '1')
				return false;
		}
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	int before_bx = -1;
	int before_by = -1;
	int before_ex = -1;
	int before_ey = -1;
	Log log;
	Log target;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
				arr[i][j] = '1';
				continue;
			}

			cin >> arr[i][j];

			if (arr[i][j] == 'B') {
				if (before_bx != -1 && before_by != -1) {
					log.x = i;
					log.y = j;

					if (log.x == before_bx)
						log.dir = true;
					else
						log.dir = false;

					before_bx = -1;
					before_by = -1;
				}
				else {
					before_bx = i;
					before_by = j;
				}
			}
			else if (arr[i][j] == 'E') {
				if (before_ex != -1 && before_ey != -1) {
					target.x = i;
					target.y = j;

					if (target.x == before_ex)
						target.dir = true;
					else
						target.dir = false;

					before_ex = -1;
					before_ey = -1;
				}
				else {
					before_ex = i;
					before_ey = j;
				}
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<Log> q;
	q.push(log);
	visited[log.x][log.y][log.dir] = 1;
	while (!q.empty()) {
		Log cur = q.front();
		q.pop();

		int cx = cur.x;
		int cy = cur.y;
		bool cd = cur.dir;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!visited[nx][ny][cd] && check(nx, ny, i, cd)) {
				visited[nx][ny][cd] = visited[cx][cy][cd] + 1;
				Log nlog;
				nlog.x = nx;
				nlog.y = ny;
				nlog.dir = cd;
				q.push(nlog);
			}
		}

		if (!visited[cx][cy][!cd] && rotate_check(cx, cy)) {
			visited[cx][cy][!cd] = visited[cx][cy][cd] + 1;
			Log nlog;
			nlog.x = cx;
			nlog.y = cy;
			nlog.dir = !cd;
			q.push(nlog);
		}
	}

	if (visited[target.x][target.y][target.dir] != 0)
		cout << visited[target.x][target.y][target.dir] - 1;
	else
		cout << visited[target.x][target.y][target.dir];
}