#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check(vector<int>& cnt, vector<string> c, vector<string>& b, vector<string>& w, int x, int y) {
	int m = x - 8;
	int n = y - 8;

	int change = 0;
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (c[i][j] != w[i - n][j - m]) change++;
		}
	}
	cnt.push_back(change);

	change = 0;
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (c[i][j] != b[i - n][j - m]) change++;
		}
	}
	cnt.push_back(change);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> chess; //chess의 원소는 체스판 행이고, n개의 행을 가지며 행의 원소는 m개임, m * n 크기
	for (int i = 0; i < n; i++) {
		string e;
		cin >> e;
		chess.push_back(e);
	}

	// 8 * 8 체스판 틀이며 black과 white는 첫 번째 행의 첫 번째 원소의 색이다.
	vector<string> black;
	vector<string> white;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			black.push_back("BWBWBWBW");
			white.push_back("WBWBWBWB");
		}
		else if (i % 2 == 1) {
			black.push_back("WBWBWBWB");
			white.push_back("BWBWBWBW");
		}
	}

	vector<int> cnt; // 다시 칠해야 하는 횟수를 저장하는 벡터
	// i - 8: 틀로 찍어서 나온 체스판의 제일 왼쪽 열의 인덱스, j - 8: 틀로 찍어서 나온 체스판의 제일 위쪽 행의 인덱스, 즉, [j - 8][i - 8]이 체스판의 제일 첫 번째 원소
	for (int i = 8; i <= m; i++) {
		for (int j = 8; j <= n; j++) {
			check(cnt, chess, black, white, i, j);
		}
	}

	cout << *min_element(cnt.begin(), cnt.end());
}