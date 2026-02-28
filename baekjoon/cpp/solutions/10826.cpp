#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Å« ¼ö µ¡¼À ±¸Çö
string add(string a, string b) {
	int maxLen = max(a.size(), b.size());
	if (a.length() == maxLen) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0;i < maxLen - b.size();i++) {
			b.push_back('0');
		}
	}
	else if (b.length() == maxLen) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0;i < maxLen - a.size();i++) {
			a.push_back('0');
		}
	}

	string ans = "";
	int carry = 0; // ¿Ã¸²¼ö
	for (int i = 0;i < maxLen;i++) {
		int digit = a[i] - '0' + b[i] - '0' + carry;
		if (digit > 9) {
			carry = digit / 10;
			digit %= 10;
		}
		else
			carry = 0;

		ans.push_back(digit + '0');
	}
	if (carry != 0)
		ans.push_back(carry + '0');
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<string> v;
	v.push_back("0");
	v.push_back("1");

	for (int i = 2;i <= n;i++) {
		string s = add(v[i - 1], v[i - 2]);
		v.push_back(s);
	}
	cout << v[n];
}