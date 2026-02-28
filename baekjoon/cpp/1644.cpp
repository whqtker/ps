#include <iostream>
#include <vector>

using namespace std;

int arr[4000001]; // 0이면 소수, 1이면 합성수

int main() {
	int n;
	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = 1;
			}
		}
	}

	vector<int> v; // 2부터 n까지 소수 저장
	for (int i = 2; i <= n; i++) {
		if (!arr[i])
			v.push_back(i);
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int l = 0, r = 0, sum = v[0], cnt = 0;
	while (1) {
		if (sum < n) {
			r++;
			if (r >= v.size())
				break;
			sum += v[r];
		}
		else if (sum > n) {
			sum -= v[l];
			l++;
		}
		else {
			cnt++;
			sum -= v[l];
			l++;
		}
	}

	cout << cnt;
}