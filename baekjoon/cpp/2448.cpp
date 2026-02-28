#include <iostream>

using namespace std;

char arr[3072][6143];

void draw(int x, int y) {
	arr[x][y] = '*';

	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	arr[x + 2][y - 2] = '*';
	arr[x + 2][y - 1] = '*';
	arr[x + 2][y] = '*';
	arr[x + 2][y + 1] = '*';
	arr[x + 2][y + 2] = '*';
}

// 높이가 3인 삼각형의 가장 상단 꼭짓점(x, y)을 기준으로 재귀를 수행한다.
void recur(int n, int x, int y) {
	if (n == 3) {
		draw(x, y);
		return;
	}

	recur(n / 2, x, y);
	recur(n / 2, x + n / 2, y - n / 2);
	recur(n / 2, x + n / 2, y + n / 2);
}

int main() {
	// 생성되는 삼각형은 시어핀스키 삼각형이다.
	int n;
	cin >> n;

	// 그려지는 공간의 크기는 n * (2n - 1)이다.
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 2 * n - 1;j++) {
			arr[i][j] = ' ';
		}
	}

	recur(n, 0, n - 1);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 2 * n - 1;j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}