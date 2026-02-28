#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <vector<int>> arr(20, vector<int>(20));
int ans;

// 기본값은 위로 이동, 다른 방향일 경우 arr를 회전한다.
void moveUp() {
	vector<vector<int>> moved(20, vector<int>(20));

	for (int i = 0;i < n;i++) {
		int able = 0;
		int first = -1;
		int second = -1;
		for (int j = 0;j < n;j++) {
			if (arr[j][i] != 0) {
				if (first == -1)
					first = arr[j][i];
				else if (second == -1) {
					second = arr[j][i];

					if (first == second) {
						moved[able][i] = first + second;
						able++;
						first = -1;
						second = -1;
					}
					else {
						moved[able][i] = first;
						able++;
						first = second;
						second = -1;
					}
				}
			}

			if (j == n - 1 && first != -1) {
				moved[able][i] = first;
			}
		}
	}

	arr = moved;
}

// arr를 시계 방향으로 1회전
void clockwise() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			swap(arr[i][j], arr[i][n - j - 1]);
		}
	}
}

// arr를 시계 반대 방향으로 1회전
void counterClockwise() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n / 2; i++) {
			swap(arr[i][j], arr[n - i - 1][j]);
		}
	}
}

void dfs(int k) {
	if (k == 5) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				ans = ans > arr[i][j] ? ans : arr[i][j];
			}
		}

		return;
	}

	vector<vector<int>> origin = arr;

	// 상
	moveUp();
	dfs(k + 1);
	arr = origin;

	// 하
	clockwise();
	clockwise();
	moveUp();
	counterClockwise();
	counterClockwise();
	dfs(k + 1);
	arr = origin;

	// 좌
	clockwise();
	moveUp();
	counterClockwise();
	dfs(k + 1);
	arr = origin;

	// 우
	counterClockwise();
	moveUp();
	clockwise();
	dfs(k + 1);
	arr = origin;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);
	cout << ans;
}