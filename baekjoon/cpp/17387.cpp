#include <iostream>
#include <algorithm>

using namespace std;

struct coor {
	long long x, y;

	bool operator<=(const coor& P)const {
		if (x != P.x)
			return x <= P.x;
		return y <= P.y;
	}
	bool operator>=(const coor& P)const {
		if (x != P.x)
			return x >= P.x;
		return y >= P.y;
	}
};

double ccw(coor A,coor B,coor C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int main() {
	coor A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

	// 선분 AB와 선분 CD에서 A와 C는 각각 B와 D보다 x 또는 y 좌표가 작도록 설정
	if (A >= B) {
		swap(A, B);
	}
	if (C >= D) {
		swap(C, D);
	}

	if (ccw(A, B, C) * ccw(A, B, D) <= 0 && ccw(C, D, A) * ccw(C, D, B) <= 0) {
		if (ccw(A, B, C) * ccw(A, B, D) == 0 && ccw(C, D, A) * ccw(C, D, B) == 0) {
			cout << (A <= D && C <= B);
		}
		else
			cout << 1;
	}
	else
		cout << 0;
}