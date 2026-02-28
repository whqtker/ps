#include <iostream>

using namespace std;

long long mat[5][5];
long long ans[5][5];
long long tmp[5][5];
int n;

void calc(long long x[5][5], long long y[5][5]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			tmp[i][j] = 0;
			for (int k = 0;k < n;k++) {
				tmp[i][j] += (x[i][k] * y[k][j]);
				tmp[i][j] %= 1000;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			x[i][j] = tmp[i][j];
		}
	}
}

void sol(long long k) {
	while (k > 0) {
		if (k % 2 == 1)
			calc(ans, mat);
		calc(mat, mat);

		k /= 2;
	}
}

int main() {
	long long b;
	cin >> n >> b;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> mat[i][j];
		}
		ans[i][i] = 1;
	}

	sol(b);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}