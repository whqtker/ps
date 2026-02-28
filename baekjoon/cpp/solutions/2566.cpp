#include <iostream>

using namespace std;

int main() {
	int max = 0;
	int row = 1;
	int col = 1;

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			int x;
			cin >> x;
			if (max < x) {
				max = x;
				row = i + 1;
				col = j + 1;
			}
		}
	}

	cout << max << "\n" << row << " " << col;
}