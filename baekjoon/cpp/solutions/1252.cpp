#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int maxLength = max(a.length(), b.length());
	int n = 0; // 올림수
	int ans;
	vector<int> v;
	for (int i = 0; i < maxLength; i++) {
		if (a.length() - 1 - i > a.length()) {
			ans = (b[b.length() - 1 - i] - '0' + n) % 2;
			n = (b[b.length() - 1 - i] - '0' + n) / 2;
			v.push_back(ans);
		}
		else if (b.length() - 1 - i > b.length()) {
			ans = (a[a.length() - 1 - i] - '0' + n) % 2;
			n = (a[a.length() - 1 - i] - '0' + n) / 2;
			v.push_back(ans);
		}
		else {
			ans = (a[a.length() - 1 - i] - '0' + b[b.length() - 1 - i] - '0' + n) % 2;
			n = (a[a.length() - 1 - i] - '0' + b[b.length() - 1 - i] - '0' + n) / 2;
			v.push_back(ans);
		}
	}
	v.push_back(n); // 마지막 올림수도 넣어야 함

	for (int i = 0; i < v.size(); i++) {
		// 이진수를 출력할 때 1로 시작해야 한다.
		if (v[v.size() - 1 - i] != 0) {
			for (int j = 0; j < v.size() - i; j++) {
				cout << v[v.size() - 1 - i - j];
			}
			break;
		}

		// 결과가 0인 경우 하나만 출력해야 한다.
		if (i == v.size() - 1 && v[i] == 0) cout << 0;
	}
}