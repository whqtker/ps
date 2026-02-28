#include <iostream>
#include <cmath>

using namespace std;

double digit[101][10]; // i번 째 자리수가 j일 때 확률

int main() {
	int k, n;

	cout << fixed;
	cout.precision(5);

	while (cin >> k >> n) {
		for (int i = 0; i <= k; i++) {
			digit[1][i] = 1.0 / (k + 1);
		}

		for (int i = 2; i <= n; i++) {
			digit[i][0] = digit[i - 1][1];

			for (int j = 0; j <= k; j++) {
				if (j == 0)
					digit[i][j] = digit[i - 1][j] + digit[i - 1][j + 1];
				else if (j == k)
					digit[i][j] = digit[i - 1][j - 1] + digit[i - 1][j];
				else
					digit[i][j] = digit[i - 1][j - 1] + digit[i - 1][j] + digit[i - 1][j + 1];

				digit[i][j] /= (k + 1);
			}
		}

		double prob = 0.0;
		for (int i = 0; i <= k; i++) {
			prob += digit[n][i];
		}
		cout << prob * 100.0 << "\n";
	}
}