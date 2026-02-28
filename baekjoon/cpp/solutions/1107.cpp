#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string n; 
	cin >> n;

	int m;
	cin >> m;
	vector<int> broken; // 고장난 숫자
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		broken.push_back(a);
	}

	vector<int> v;
	for (int i = 0; i <= 999999; i++) {
		bool flag = false;
		for (int j = 0; j < broken.size(); j++) {
			// i에 고장난 숫자가 있는지 체크
			if (to_string(i).find(to_string(broken[j])) != string::npos) {
				flag = true;
				break;
			}
		}
		// 고장난 숫자가 없다면 눌러야 하는 버튼의 최솟값을 계산한다.
		if (flag == false) {
			int cnt = abs(i - stoi(n));
			int tmp = i;
			int digit = 0;
			while (tmp > 0) {
				tmp /= 10;
				digit++;
			}
			if (i == 0)
				cnt += 1;
			else
				cnt += digit;
			v.push_back(cnt);
		}
	}

	v.push_back(abs(100 - stoi(n))); // 기존 채널(100)에서 +, -를 누르는 횟수
	cout << *min_element(v.begin(), v.end());
}