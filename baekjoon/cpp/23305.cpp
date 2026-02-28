#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> lec(1000001); // 수업 번호가 곧 인덱스임.

	// 인덱스(수업 번호)에 해당하는 값이 수업을 가지고 있는 학생의 수가 됨.
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		lec[a]++;
	}

	// 교환을 통해 수강할 수업이 들어오면 1을 뺀다. 만약 0이라면 교환 불가.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		if (lec[b] >= 1)
			lec[b] -= 1;
		else
			cnt++;
	}

	cout << cnt;
}