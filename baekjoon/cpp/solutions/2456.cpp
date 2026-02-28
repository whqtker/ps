#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sameScore(int a, int b, vector<vector<int>> vv) {
	if (a == b)
		return a + 1;
	else if (vv[a][1] > vv[b][1])
		return a + 1;
	else if (vv[a][1] < vv[b][1])
		return b + 1;
	else if (vv[a][0] > vv[b][0])
		return a + 1;
	else if (vv[a][0] < vv[b][0])
		return b + 1;
	else return 0;
}

int main() {
	int n;
	cin >> n;

	vector<int> v(3);
	vector<vector<int>> vv(3, vector<int>(2));
	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[0] += a;
		v[1] += b;
		v[2] += c;

		if (a == 2)vv[0][0]++;
		if (a == 3)vv[0][1]++;
		if (b == 2)vv[1][0]++;
		if (b == 3)vv[1][1]++;
		if (c == 2)vv[2][0]++;
		if (c == 3)vv[2][1]++;
	}

	int maxScore = *max_element(v.begin(), v.end());
	int winner;
	if (maxScore == v[0] && maxScore == v[1] && maxScore == v[2]) {
		if (sameScore(0, 1, vv) != 0 || sameScore(0, 2, vv) != 0 || sameScore(1, 2, vv) != 0) {
			if (sameScore(0, 1, vv) == 0)
				winner = sameScore(sameScore(0, 2, vv) - 1, sameScore(1, 2, vv) - 1, vv);
			else if (sameScore(0, 2, vv) == 0)
				winner = sameScore(sameScore(0, 1, vv) - 1, sameScore(1, 2, vv) - 1, vv);
			else if (sameScore(1, 2, vv) == 0)
				winner = sameScore(sameScore(0, 2, vv) - 1, sameScore(0, 1, vv) - 1, vv);
			else
				winner = sameScore(sameScore(0, 2, vv) - 1, sameScore(0, 1, vv) - 1, vv);
		}
		else
			winner = 0;
	}
	else if (maxScore == v[0]) {
		winner = 1;
		if (maxScore == v[1]) {
			winner = sameScore(winner - 1, 1, vv);
		}
		else if (maxScore == v[2]) {
			winner = sameScore(winner - 1, 2, vv);
		}
	}
	else if (maxScore == v[1]) {
		winner = 2;
		if (maxScore == v[2]) {
			winner = sameScore(winner - 1, 2, vv);
		}
	}
	else
		winner = 3;

	cout << winner << " " << maxScore;
}