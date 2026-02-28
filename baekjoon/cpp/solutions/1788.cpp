#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int SIZE = 2000001;
const int MOD = 1000000000;
int arr[SIZE];

int main() {
	// arr[0]은 n = -1000000인 피보나치 수, arr[2000000]은 n = 1000000인 피보나치 수이다.
	memset(arr, 0, sizeof(int) * SIZE);
	int n;
	cin >> n;

	// 기저 조건 정의
	arr[1000000] = 0;
	arr[1000001] = 1;

	int idx = n + 1000000;
	if (idx > 1000001) {
		int tmp = 1000002;
		while (tmp <= idx) {
			arr[tmp] = (arr[tmp - 1] + arr[tmp - 2]) % MOD;
			tmp++;
		}
	}
	else if (idx < 1000000) {
		int tmp = 999999;
		while (tmp >= idx) {
			arr[tmp] = (arr[tmp + 2] - arr[tmp + 1]) % MOD;
			tmp--;
		}
	}

	int sign = 0;
	if (arr[idx] < 0)
		sign = -1;
	else if (arr[idx] > 0)
		sign = 1;

	cout << sign << "\n";
	cout << abs(arr[idx]);
}