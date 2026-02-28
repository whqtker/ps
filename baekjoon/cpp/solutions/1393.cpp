#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b; // 정류장 좌표
	cin >> a >> b;

	double m, n, dx, dy; // 열차 위치 및 x, y 증가량
	cin >> m >> n >> dx >> dy;

	// 열차의 이동 경로가 x축과 수직인 경우
	if (dx == 0) {
		// 열차 이동 방향에 정류장이 없는 경우
		if (dy * (b - n) < 0)
			cout << m << " " << n;
		else
			cout << m << " " << b;
	}

	// 열차 이동 방향에 정류장이 없는 경우 
	else if (dx * (a - m) < 0 || dy * (b - n) < 0) {
		cout << m << " " << n;
	}
	else {
		double k = dy / dx; // 기울기
		int x = (a + b * k + pow(k, 2) * m - n * k) / (pow(k, 2) + 1);
		int y = k * (x - m) + n;
		cout << x << " " << y;
	}
}