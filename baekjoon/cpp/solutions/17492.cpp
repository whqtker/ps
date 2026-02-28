#include <iostream>

using namespace std;

int n;
int cnt;
int arr[10][10];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
bool flag = false;

// 남은 바둑알의 수는 cnt - k이다.
void bt(int k) {
	if (cnt - k == 1) {
		flag = true;
		return;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 2) {
				for (int idx = 0;idx < 8;idx++) {
					int nx = i + dx[idx];
					int ny = j + dy[idx];

					if (nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 2) {
						int dest_x = i + 2 * dx[idx];
						int dest_y = j + 2 * dy[idx];

						if (dest_x >= 0 && dest_y >= 0 && dest_x < n && dest_y < n && arr[dest_x][dest_y] == 0) {
							arr[nx][ny] = 0;
							arr[i][j] = 0;
							arr[dest_x][dest_y] = 2;

							bt(k + 1);

							arr[nx][ny] = 2;
							arr[i][j] = 2;
							arr[dest_x][dest_y] = 0;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				cnt++;
		}
	}

	bt(0);
	if (flag)
		cout << "Possible";
	else
		cout << "Impossible";
}