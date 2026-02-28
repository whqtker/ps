#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int w, h; // w: 가로 길이, h: 세로 길이
	int a, b; // 입력받을 수
	int r1, r2; // a, b를 4로 나눈 나머지

	cin >> a >> b;
	if (a % 4 == 0) r1 = 4;
	else r1 = a % 4;
	if (b % 4 == 0) r2 = 4;
	else r2 = b % 4;

	h = abs(r1 - r2); // 세로 길이는 입력된 두 수의 mod값의 차이이다.
	w = abs((a - r1) - (b - r2)) / 4; // 가로 길이는 나머지를 뺀 값을 서로 빼고 4로 나눈 몫이다.

	cout << w + h;
}