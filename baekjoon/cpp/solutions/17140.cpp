#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[100][100];

int rowLen = 3;
int colLen = 3;

void row() {
	rowLen = 0;
	for (int i = 0; i < colLen; i++) {
		unordered_map<int, int> um; // { ¼ö, µîÀåÈ½¼ö }

		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 0) continue;

			um[arr[i][j]]++;
		}

		rowLen = max(rowLen, (int)um.size() * 2);

		vector<pair<int, int>> tmp; // { µîÀåÈ½¼ö, ¼ö }
		for (auto it : um) {
			tmp.push_back({ it.second,it.first });
		}

		sort(tmp.begin(), tmp.end());

		for (int j = 0; j < 100; j += 2) {
			if (j / 2 >= tmp.size()) {
				for (int k = j; k < 100; k++) {
					arr[i][k] = 0;
				}

				break;
			}

			arr[i][j] = tmp[j / 2].second;
			arr[i][j + 1] = tmp[j / 2].first;
		}
	}
}

void col() {
	colLen = 0;
	for (int i = 0; i < rowLen; i++) {
		unordered_map<int, int> um;

		for (int j = 0; j < 100; j++) {
			if (arr[j][i] == 0) continue;

			um[arr[j][i]]++;
		}

		colLen = max(colLen, (int)um.size() * 2);

		vector<pair<int, int>> tmp; // { µîÀåÈ½¼ö, ¼ö }
		for (auto it : um) {
			tmp.push_back({ it.second,it.first });
		}

		sort(tmp.begin(), tmp.end());

		for (int j = 0; j < 100; j += 2) {
			if (j / 2 >= tmp.size()) {
				for (int k = j; k < 100; k++) {
					arr[k][i] = 0;
				}

				break;
			}

			arr[j][i] = tmp[j / 2].second;
			arr[j + 1][i] = tmp[j / 2].first;
		}
	}
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {
		if (arr[r - 1][c - 1] == k) {
			cout << i;
			return 0;
		}

		if (rowLen <= colLen) {
			row();
		}
		else {
			col();
		}
	}

	cout << -1;
}