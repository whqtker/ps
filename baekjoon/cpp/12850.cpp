#include <iostream>

#define MOD 1000000007

using namespace std;

long long tmp[8][8];
long long ans[8][8];

void calc(long long x[8][8], long long y[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				tmp[i][j] += (x[i][k] * y[k][j]);
				tmp[i][j] %= MOD;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			x[i][j] = tmp[i][j];
		}
	}
}

int main() {
	int n;
	cin >> n;

	long long graph[8][8] = {
			{0, 1, 1, 0, 0, 0, 0, 0},
			{1, 0, 1, 1, 0, 0, 0, 0},
			{1, 1, 0, 1, 1, 0, 0, 0},
			{0, 1, 1, 0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0, 1, 0, 1},
			{0, 0, 0, 1, 1, 0, 1, 0},
			{0, 0, 0, 0, 0, 1, 0, 1},
			{0, 0, 0, 0, 1, 0, 1, 0}
	};

	for (int i = 0; i < 8; i++) {
		ans[i][i] = 1;
	}

	while (n > 0) {
		if (n % 2 == 1)
			calc(ans, graph);
		
		calc(graph, graph);

		n /= 2;
	}

	cout << ans[0][0];
}