#include <iostream>
#include <algorithm>

using namespace std;

int maxVal[2][3]; // maxVal[n][m]: m번 째 수의 최댓값, n = 0은 이전, 1은 현재
int minVal[2][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (i == 0) {
			maxVal[0][0] = a;
			maxVal[0][1] = b;
			maxVal[0][2] = c;

			minVal[0][0] = a;
			minVal[0][1] = b;
			minVal[0][2] = c;
		}
		else if (i == 1) {
			maxVal[1][0] = max(maxVal[0][0], maxVal[0][1]) + a;
			maxVal[1][1] = max({ maxVal[0][0], maxVal[0][1],maxVal[0][2] }) + b;
			maxVal[1][2] = max(maxVal[0][1], maxVal[0][2]) + c;

			minVal[1][0] = min(minVal[0][0], minVal[0][1]) + a;
			minVal[1][1] = min({ minVal[0][0], minVal[0][1],minVal[0][2] }) + b;
			minVal[1][2] = min(minVal[0][1], minVal[0][2]) + c;
		}
		else {
			maxVal[0][0] = maxVal[1][0];
			maxVal[0][1] = maxVal[1][1];
			maxVal[0][2] = maxVal[1][2];

			minVal[0][0] = minVal[1][0];
			minVal[0][1] = minVal[1][1];
			minVal[0][2] = minVal[1][2];

			maxVal[1][0] = max(maxVal[0][0], maxVal[0][1]) + a;
			maxVal[1][1] = max({ maxVal[0][0], maxVal[0][1],maxVal[0][2] }) + b;
			maxVal[1][2] = max(maxVal[0][1], maxVal[0][2]) + c;

			minVal[1][0] = min(minVal[0][0], minVal[0][1]) + a;
			minVal[1][1] = min({ minVal[0][0], minVal[0][1],minVal[0][2] }) + b;
			minVal[1][2] = min(minVal[0][1], minVal[0][2]) + c;
		}
	}

	if (n == 1)
		cout << max({ maxVal[0][0],maxVal[0][1], maxVal[0][2] }) << " " << min({ minVal[0][0],minVal[0][1], minVal[0][2] });
	else
		cout << max({ maxVal[1][0],maxVal[1][1], maxVal[1][2] }) << " " << min({ minVal[1][0],minVal[1][1], minVal[1][2] });
}