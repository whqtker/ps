#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;

bool isFit(vector<int> row, vector<int> col, int i, int j) {
	// 먼저 1번 스티커를 최좌상단에 위치한다. limit_h과 limit_w은 최대로 가능한 h 또는 w의 길이.
	int limit_h = (h - row[i] == 0) ? h : h - row[i];
	int limit_w = (w - col[i] == 0) ? w : w - col[i];

	// 1번 스티커가 올바르게 붙여지지 않은 경우
	if ((limit_h < 0 || limit_w < 0))
		return false;

	// 1번 스티커가 모눈종이를 넘어가는 경우
	if ((row[i] > max(h, w)) || (col[i] > max(h, w)))
		return false;

	// 2번 스티커가 모눈종이를 넘어가는 경우
	if ((row[j] > max(h, w)) || (col[j] > max(h, w)))
		return false;

	// 1번 스티커가 전체 모눈종이를 다 덮는 경우
	if (limit_w == w && limit_h == h)
		return false;

	// 1번 스티커가 모눈종이의 한 쪽 모서리를 다 덮는 경우
	if (limit_w == w || limit_h == h) {
		if ((col[j] <= limit_w && row[j] <= limit_h) || (row[j] <= limit_w && col[j] <= limit_h) || (col[j] <= limit_h && row[j] <= limit_w) || (row[j] <= limit_h && col[j] <= limit_w))
			return true;
		else
			return false;
	}

	// 2번 스티커가 최우하단에 위치할 수 있는 경우 (빈 공간이 」형태라고 가정)
	if ((row[j] <= h && col[j] <= limit_w) || (col[j] <= h && row[j] <= limit_w) || (row[j] <= w && col[j] <= limit_h) || (col[j] <= w && row[j] <= limit_h))
		return true;

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> h >> w >> n;

	vector<int> row;
	vector<int> col;
	for (int i = 0;i < n;i++) {
		int r, c;
		cin >> r >> c;
		row.push_back(r);
		col.push_back(c);
	}

	int m = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i != j && (isFit(row, col, i, j) || (isFit(col, row, i, j)))) {
				int s = row[i] * col[i] + row[j] * col[j];
				m = (m > s) ? m : s;
			}
		}
	}

	cout << m;
}