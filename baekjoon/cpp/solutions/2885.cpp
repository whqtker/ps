#include <iostream>
#include <cmath>

using namespace std;

int powOf2[21];

int main() {
	int k;
	cin >> k;

	// k를 2^k의 수의 합으로 표현한다. 항의 개수가 분할 횟수
	powOf2[0] = 1;
	for (int i = 1; i <= 20; i++) {
		powOf2[i] = powOf2[i - 1] * 2;
	}

	int i = ceil(log2(k));
	int num = pow(2, i);
	int cnt = 0; // 분할 횟수
	while (k > 0) {
		if (k - num >= 0) {
			k -= num;
		}
		else {
			cnt++;
			num /= 2;
		}
	}

	cout << (int)pow(2, i) << " " << cnt;
}