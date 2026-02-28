#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int result; // 계산 결과의 일의 자리
	int next = 0; // 계산 결과의 십의 자리
	vector<int> ret; // 최종 답

	int x = max(a.length(), b.length()); // 우변을 바로 for문에 넣으면 안 됨. for문을 돌면서 문자열의 길이가 바뀌기 때문.
	for (int i = 0; i < x; i++) {
		result = 0;
		if (!a.empty()) {
			result += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			result += b.back() - '0';
			b.pop_back();
		}
		result += next;
		next = result / 10;
		result %= 10;

		ret.push_back(result);
	}

	if (next == 1)
		ret.push_back(next);

	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i];
	}
}