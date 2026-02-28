#include <iostream>

using namespace std;

int board[101][101];

int main() {
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;

	// 행 확인
	for (int i = 0; i < n; i++) {
		int cnt = 1; // 높이가 같은 길의 수
		bool down = false; // 내리막 경사로 설치해야하는지
		bool failed = false;
		for (int j = 0; j < n - 1; j++) {
			// 내리막 경사로 설치 후 초기화
			if (down && cnt >= l) {
				cnt = 0;
				down = false;
			}

			if (board[i][j] == board[i][j + 1]) {
				cnt++;
			}
			// 다음 길이 높은 경우
			else if (board[i][j] - board[i][j + 1] == -1) {
				if (cnt < l) {
					failed = true;
					break;
				}
				down = false;
				cnt = 1;
			}
			// 다음 길이 낮은 경우
			else if (board[i][j] - board[i][j + 1] == 1) {
				if (down) {
					failed = true;
					break;
				}
				down = true;
				cnt = 1;
			}
			// 높이 차가 2 이상
			else {
				failed = true;
				break;
			}
		}

		if (down && cnt < l) {
			failed = true;
		}
		if (!failed) ans++;
	}

	// 열 확인
	for (int j = 0; j < n; j++) {
		int cnt = 1; // 높이가 같은 길의 수
		bool down = false; // 높이가 낮아졌는가
		bool failed = false;
		for (int i = 0; i < n - 1; i++) {
			if (down && cnt >= l) {
				cnt = 0;
				down = false;
			}

			if (board[i][j] == board[i + 1][j]) {
				cnt++;
			}
			else if (board[i][j] - board[i + 1][j] == -1) {
				if (cnt < l) {
					failed = true;
					break;
				}
				down = false;
				cnt = 1;
			}
			else if (board[i][j] - board[i + 1][j] == 1) {
				if (down) {
					failed = true;
					break;
				}
				down = true;
				cnt = 1;
			}
			else {
				failed = true;
				break;
			}
		}

		if (down && cnt < l) {
			failed = true;
		}
		if (!failed) ans++;
	}

	cout << ans;
}