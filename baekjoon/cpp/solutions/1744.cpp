#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 수열의 크기가 1인 경우 입력받은 수를 그대로 출력한다.
	if (n == 1) {
		cout << v[0];
		return 0;
	}

	sort(v.begin(), v.end());

	long long ans = 0;
	int pos = 0; // 처음으로 양수인 수의 인덱스

	// 값이 음수 또는 0인 부분을 연산한다. 작은 수부터 묶는다.
	for (int i = 1;i < n;i++) {
		if (v[i] > 0) {
			pos = i;
			// 배열의 모든 수가 양수인 경우는 i - 1번 째 수가 처음으로 양수이다.
			if (v[i - 1] > 0)
				pos = i - 1;
			break;
		}

		// 작은 수 부터 묶을 때 이미 묶인 수는 묶지 않아야 한다.
		bool cond1 = v[i - 1] == -1001 || v[i] == -1001;
		if (!cond1) {
			ans += v[i - 1] * v[i];
			// 묶인 수는 -1001로 값을 바꾸어 표시한다.
			v[i - 1] = -1001;
			v[i] = -1001;
		}

		// 묶이지 않은 음수가 있을 경우 정답에 더한다.
		if (i == n - 1 && v[i] != -1001)
			ans += v[i];
	}

	// 양수인 부분을 연산한다. 큰 수부터 묶는다.
	for (int i = n - 1;i >= pos;i--) {
		// i가 0인 경우 인덱스 에러 발생, 따로 처리한다.
		if (i == 0) {
			if (v[i + 1] == -1001 && v[i] != -1001)
				ans += v[i];
			else if (v[i] != -1001 && v[i + 1] != -1001)
				ans += v[i] * v[i + 1];
			break;
		}
		// (1, n), (음수, 양수), (0, 양수), 이미 묶인 수는 묶지 않는다.
		bool cond1 = v[i - 1] == 1 && v[i] > 0;
		bool cond2 = v[i] > 0 && v[i - 1] <= 0;
		bool cond3 = v[i] == -1001 || v[i - 1] == -1001;
		if (!cond1 && !cond2 && !cond3) {
			ans += v[i - 1] * v[i];
			// 묶인 수는 -1001로 값을 바꾸어 표시한다.
			v[i - 1] = -1001;
			v[i] = -1001;
		}
		else {
			// (1, n)인 경우 먼저 두 번째 수를 더한다.
			if (cond1) {
				ans += v[i];
				v[i] = -1001;
			}
		}

		// 묶이지 않은 양수가 있을 경우 정답에 더한다.
		if (i == pos && v[i] != -1001)
			ans += v[i];
	}

	// 묶이지 않은 음수 또는 0이 있을 경우 정답에 더한다.
	if (pos - 1 >= 0 && v[pos - 1] != -1001)
		ans += v[pos - 1];

	cout << ans;
}