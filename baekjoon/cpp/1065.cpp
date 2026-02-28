#include <iostream>

using namespace std;

int main() {
	//일단 1부터 99까지의 수는 모두 한수이다. 100부터 한수인지 확인하는 코드를 구현하면 될 것이다.
	//백의 자리까지 있는 수(100 ~ 999)가 한수인지 판별하는 코드를 구현해야 할 것이다. 1000까지 입력받는다고 되어 있지만 어차피 1000은 한수가 아니다.

	int sum = 0;

	int num;
	cin >> num;

	if (num < 100) { //99 이하인 수는 본인 수가 곧 한수의 총 개수이므로 그대로 출력해준다.
		cout << num;
	}
	else { //else문으로 넘어온 수는 모두 백의 자리까지 있는 수일 것이다.
		sum = 99;
		for (int i = 100; i <= num; i++) {

			int hundreds = i / 100;
			int tens = (i % 100 - i % 10) / 10;
			int ones = i % 10;

			if (tens - ones == hundreds - tens) {
				sum++;
			}
		}

		cout << sum;
	}
}