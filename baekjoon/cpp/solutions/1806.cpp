#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// (전체 합) - (0부터 i까지의 합) - (j부터 n-1까지의 합) = m
	int tot = 0;
	vector<int> sum1, sum2;
	sum1.push_back(0);
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		tot += x;

		sum1.push_back(sum1[i] + x);
	}

	for (int i = 0;i < n;i++) {
		sum2.push_back(tot - sum1[i]);
	}
	sum2.push_back(0);

	int l = 0, r = 0;
	int ans = 100000001;
	while (1) {
		if (tot - sum1[l] - sum2[r] < m) {
			r++;
			if (r > n)
				break;
		}
		else if (tot - sum1[l] - sum2[r] >= m) {
			if (r - l < ans)
				ans = r - l;

			l++;
		}
	}

	if (ans == 100000001)
		cout << 0;
	else
		cout << ans;
}