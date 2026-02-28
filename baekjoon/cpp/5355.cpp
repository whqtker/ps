#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		double d;
		string s;
		vector<string> op;

		cin >> d;

		// cin.get()은 공백, 개행문자도 입력받는다. cin은 공백, 개행문자를 무시한다.
		while (1) {
			s = cin.get();
			if (s == "\n") break;
			else if (s != " ")
				op.push_back(s);
		}

		for (int j = 0; j < op.size(); j++) {
			if (op[j] == "@") d *= 3;
			else if (op[j] == "%") d += 5;
			else if (op[j] == "#") d -= 7;
		}

		// 소수점 자리수를 설정하는 부분, 소수점 아래 0 출력
		cout << fixed;
		cout << showpoint << setprecision(2);

		cout << d << "\n";
	}
}