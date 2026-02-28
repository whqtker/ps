#include <iostream>
#include <algorithm>

using namespace std;

int mat[101][101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			int x;
			cin >> x;
			mat[i][j] = x;
		}
	}

	int front = 0, side = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			front += abs(mat[i][j] - mat[i][j - 1]);
		}
		front += mat[i][m];
	}

	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			side += abs(mat[j][i] - mat[j - 1][i]);
		}
		side += mat[n][i];
	}

	cout << m * n * 2 + front + side;
}