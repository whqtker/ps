#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
deque<pair<int, int>> dq; // 뱀이 위치한 좌표 저장
int arr[101][101]; // 뱀이 위치한 좌표 저장
char turn[10001]; // 뱀의 방향 전환 정보 저장
int apple[101][101]; // 사과 좌표 저장

bool exit(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > n)
		return true;

	return arr[x][y]; // 뱀의 머리가 뱀과 만나는 경우 true 리턴
}

void move(int* x, int* y, int dir) {
	if (dir == 1)
		*y += 1;
	else if (dir == 3)
		*y -= 1;
	else if (dir == 2)
		*x += 1;
	else if (dir == 0)
		*x -= 1;
}

int main() {
	int k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		apple[a][b] = 1;
	}

	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		turn[x] = c;
	}

	int dir = 1; // 0부터 시계 방향으로 북, 동, 남, 서
	int t = 0;
	dq.push_back({ 1,1 });
	arr[1][1] = 1;
	while (1) {
		t++;

		int x = dq.front().first;
		int y = dq.front().second;

		move(&x, &y, dir);
		dq.push_front({ x,y });

		if (exit(x, y))
			break;

		arr[x][y] = 1;
		if (!apple[x][y]) {
			arr[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else
			apple[x][y] = 0;

		if (turn[t] != '\0') {
			if (turn[t] == 'L')
				dir = (dir + 3) % 4;
			else if (turn[t] == 'D')
				dir = (dir + 1) % 4;
		}
	}

	cout << t;
}