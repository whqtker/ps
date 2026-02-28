#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// posi~~: a, b가 양수 또는 0일 때 사칙연산 수행
string posiAdd(string a, string b) {
	string ans;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int maxDigit = max(a.length(), b.length());

	int carry = 0; // 받아올림수
	for (int i = 0; i < maxDigit; i++) {
		// a의 i번 째 인덱스의 원소가 존재하지 않을 때
		if (i >= a.length()) {
			int n = b[i] - '0' + carry; // 계산 결과의 일의 자리 수
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		// b의 i번 째 인덱스의 원소가 존재하지 않을 때
		else if (i >= b.length()) {
			int n = a[i] - '0' + carry; // 계산 결과의 일의 자리 수
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		else {
			int n = a[i] - '0' + b[i] - '0' + carry; // 계산 결과의 일의 자리 수
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
	}
	if (carry != 0) ans += carry + '0'; // 마지막 받아올림수를 고려해야 한다.
	reverse(ans.begin(), ans.end());
	return ans;
}

string posiSub(string a, string b) {
	string ans;
	string cal_a = a;
	string cal_b = b;
	// 자리수가 더 큰 수가 더 큰 수이다.
	if (cal_a.length() > cal_b.length()) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_a.size(); i++) {
			// 받아내려야 하는 상황
			int n; // 계산 결과의 일의 자리수
			// b의 i번 째 인덱스의 원소가 존재하지 않을 때
			if (i >= cal_b.length()) {
				// 자릿수가 0보다 작은 수일 때
				if (cal_a[i] - '0' < 0) {
					cal_a[i + 1] -= 1;
					n = cal_a[i] + 10 - '0';
				}
				else
					n = cal_a[i] - '0';
			}
			else if (cal_a[i] - '0' - cal_b[i] + '0' < 0) {
				cal_a[i + 1] -= 1;
				n = cal_a[i] + 10 - '0' - cal_b[i] + '0';
			}
			else {
				n = cal_a[i] - '0' - cal_b[i] + '0';
			}
			ans += n + '0';
		}
	}
	else if (cal_a.length() < cal_b.length()) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_b.size(); i++) {
			int n; // 계산 결과의 일의 자리수
			// a의 i번 째 인덱스의 원소가 존재하지 않을 때
			if (i >= cal_a.length()) {
				// 자릿수가 0보다 작은 수일 때
				if (cal_b[i] - '0' < 0) {
					cal_b[i + 1] -= 1;
					n = cal_b[i] + 10 - '0';
				}
				else
					n = cal_b[i] - '0';
			}
			// 받아내려야 하는 상황
			else if (cal_b[i] - '0' - cal_a[i] + '0' < 0) {
				cal_b[i + 1] -= 1;
				n = cal_b[i] + 10 - '0' - cal_a[i] + '0';
			}

			else {
				n = cal_b[i] - '0' - cal_a[i] + '0';
			}
			ans += n + '0';
		}
	}
	// 자리수가 같으면 맨 앞자리 수를 비교한다. 두 수가 같은 경우는 여기서 처리한다.
	else if (cal_a >= cal_b) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_a.size(); i++) {
			// 받아내려야 하는 상황
			int n; // 계산 결과의 일의 자리수
			// b의 i번 째 인덱스의 원소가 존재하지 않을 때
			if (i >= cal_b.length()) {
				// 자릿수가 0보다 작은 수일 때
				if (cal_a[i] - '0' < 0) {
					cal_a[i + 1] -= 1;
					n = cal_a[i] + 10 - '0';
				}
				else n = cal_a[i] - '0';
			}
			else if (cal_a[i] - '0' - cal_b[i] + '0' < 0) {
				cal_a[i + 1] -= 1;
				n = cal_a[i] + 10 - '0' - cal_b[i] + '0';
			}
			else {
				n = cal_a[i] - '0' - cal_b[i] + '0';
			}
			ans += n + '0';
		}
	}
	else {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_b.size(); i++) {
			// 받아내려야 하는 상황
			int n; // 계산 결과의 일의 자리수
			// a의 i번 째 인덱스의 원소가 존재하지 않을 때
			if (i >= cal_a.length()) {
				// 자릿수가 0보다 작은 수일 때
				if (cal_b[i] - '0' < 0) {
					cal_b[i + 1] -= 1;
					n = cal_b[i] + 10 - '0';
				}
				else n = cal_b[i] - '0';
			}
			else if (cal_b[i] - '0' - cal_a[i] + '0' < 0) {
				cal_b[i + 1] -= 1;
				n = cal_b[i] + 10 - '0' - cal_a[i] + '0';
			}
			else {
				n = cal_b[i] - '0' - cal_a[i] + '0';
			}
			ans += n + '0';
		}
	}
	// ans의 끝에 0이 있을 수 있다. 이 경우 없애주어야 한다. ex) 19 - 18 = 01 (x) 1 (o)
	reverse(ans.begin(), ans.end());

	int idx = 0;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == '0') idx = i;
		else {
			idx = i;
			break;
		}
	}
	ans = ans.substr(idx, ans.length() - idx);

	// b가 더 큰 경우 앞에 -를 붙인다.
	if (a.length() < b.length()) {
		string minus = "-";
		minus += ans;
		ans = minus;
	}
	else if (a.length() == b.length() && a < b) {
		string minus = "-";
		minus += ans;
		ans = minus;
	}

	return ans;
}

string posiMul(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<string> part; // a와 b의 자릿수를 곱해 나온 결과값. part의 원소들을 더한 값이 최종 결과.
	for (int i = 0; i < b.size(); i++) {
		int carry = 0; // 받아올림수
		string ans;
		for (int j = 0; j < a.size(); j++) {
			int n = (a[j] - '0') * (b[i] - '0') + carry; // 계산 결과의 일의 자리 수
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		if (carry != 0) ans += carry + '0';

		// 원래 곱셈과정에서 십의 자리와 곱할 때는 뒤에 한 칸 띄고 계산한다. 이 과정을 수행해야 한다.
		reverse(ans.begin(), ans.end());
		for (int j = 0; j < i; j++) {
			ans += '0';
		}
		part.push_back(ans);
	}

	string sum = part[0];
	for (int i = 0; i < part.size() - 1; i++) {
		posiAdd(sum, part[i + 1]);
		sum = posiAdd(sum, part[i + 1]);
	}

	// 결과 전처리
	int idx = 0;
	for (int i = 0; i < sum.length(); i++) {
		if (sum[i] == '0') idx = i;
		else {
			idx = i;
			break;
		}
	}
	sum = sum.substr(idx, sum.length() - idx);
	return sum;
}

string add(string a, string b) {
	// 둘 다 음수일 때 절댓값끼리 합에 - 를 붙인다.
	if (a[0] == '-' && b[0] == '-') {
		string ret = "-";
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		ret += posiAdd(a, b);
		return ret;
	}
	// a가 음수일 때
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		return posiSub(b, a);
	}
	// b가 음수일 때
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		return posiSub(a, b);
	}
	// 둘 다 양수일 때
	else return posiAdd(a, b);
}

string sub(string a, string b) {
	// 둘 다 음수일 때 - a - (- b) = b - a
	if (a[0] == '-' && b[0] == '-') {
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		return posiSub(b, a);
	}
	// a가 음수일 때 - a - b = - (a + b)
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		string ret = "-";
		ret += posiAdd(a, b);
		return ret;
	}
	// b가 음수일 때
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		return posiAdd(a, b);
	}
	// 둘 다 양수일 때
	else return posiSub(a, b);
}

string mul(string a, string b) {
	// 둘 다 음수일 때
	if (a[0] == '-' && b[0] == '-') {
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		return posiMul(a, b);
	}
	// a가 음수일 때
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		string ret = "-";
		ret += posiMul(a, b);
		return ret;
	}
	// b가 음수일 때
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		string ret = "-";
		ret += posiMul(a, b);
		return ret;
	}
	// 둘 다 양수일 때
	else return posiMul(a, b);
}

int main() {
	string a, b;
	cin >> a >> b;

	// 전처리 과정 (입력된 수가 0으로 시작하는 경우)
	int idx = 0;
	bool nega = false; // 입력된 수가 음수인지 판별
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '-' && a[i] != '0') {
			idx = i;
			break;
		}
		else if (a[i] == '-') nega = true;
	}
	a = a.substr(idx);
	if (nega == true && a[0] != 0) {
		string minus = "-";
		minus += a;
		a = minus;
	}

	idx = 0;
	nega = false;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] != '-' && b[i] != '0') {
			idx = i;
			break;
		}
		else if (b[i] == '-') nega = true;
	}
	b = b.substr(idx);
	if (nega == true && b[0] != 0) {
		string minus = "-";
		minus += b;
		b = minus;
	}

	// 덧셈
	cout << add(a, b) << "\n";

	// 뺄셈
	cout << sub(a, b) << "\n";

	// 곱셈
	cout << mul(a, b) << "\n";
}