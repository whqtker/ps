#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // n번째로 감소하는 수 출력
	cin >> n;

	vector<int> v(1);
	int digit = 0; // v의 자릿수는 digit + 1, digit은 v의 가장 작은 자릿수의 인덱스를 참조함
	int ret = 0;
	while (n != ret) {
		// 수를 1만큼 증가시킴
		// 단, 벡터의 모든 원소가 9이면 자릿수를 증가시켜야 함. ex) 9 -> 10, 999 -> 1000
		vector<int> isNine(digit + 1, 9);
		if (v == isNine) {
			digit++;
			v = vector<int>(digit + 1, 0);
			v[0] = 1;
		}
		else {
			v[digit]++;
			// 19 -> 20이 되야 함
			if (v[digit] == 10) {

			}
		}

		vector<int> sorted = v;
		sort(sorted.rbegin(), sorted.rend()); // 내림차순 정렬
		sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 11 같은 경우는 감소하는 수가 아니다.
		if (v == sorted) {
			ret++;
		}
	}

	cout << ret;
}