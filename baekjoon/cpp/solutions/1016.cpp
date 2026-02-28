#include <iostream>
#include <cmath>

using namespace std;

int arr[1000001]; // a인 수의 인덱스는 0 / 즉, 특정 수 x의 인덱스는 x - a

int main() {
	long long a, b;
	cin >> a >> b;

	// p^2으로 나누어 떨어진다면 제곱 ㄴㄴ 수가 될 수 없다. (p는 소수)
	// a부터 p^2으로 나누어 떨어지는 수들을 arr에 표기하여, b 이전까지 진행한다.
	// 즉, 표기된 수들은 제곱 ㄴㄴ 수가 될 수 없다.

	long long p = 2; // 2부터 시작
	long long ans = b - a + 1;

	while (p * p <= b) {
		// start: a보다 큰 (p * p) * k의 값 중 a와 가장 가까운 수에서의 k
		long long start = a / (p * p);
		if (start * (p * p) < a)
			start++;

		// a와 b 사이의 수 중 p * p의 배수인 수들을 표시
		while (start * (p * p) <= b) {
			// 이미 표기되었다면 스킵
			if (!arr[start * (p * p) - a]){
				arr[start * (p * p) - a] = 1;
				ans--;
			}

			start++;
		}

		p++;
	}

	cout << ans;
}