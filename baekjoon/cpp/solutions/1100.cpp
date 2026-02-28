#include <iostream>

using namespace std;

int main() {
	char chessBoard[8][8] = {};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> chessBoard[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int j;
		if (i % 2 == 0)
			j = 0;
		else
			j = 1;
		for (; j < 8; j += 2) {
			if (chessBoard[i][j] == 'F')
				cnt++;
		}
	}

	cout << cnt;
}