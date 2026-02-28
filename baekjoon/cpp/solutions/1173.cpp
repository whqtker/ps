#include <iostream>

using namespace std;

int main() {
	int N, m, M, T, R; // N: 운동을 해야 하는 시간, m: 초기맥박/최소맥박, M: 최대맥박, T: 운동을 하고 추가되는 맥박, R: 휴식을 하고 줄어드는 맥박
	cin >> N >> m >> M >> T >> R;

	int t = 0; // 전체 시간
	int e = 0; // 실제로 운동한 시간
	int c = m; // 현재 맥박

	// 1. 운동은 할 수 있을 때 해야 함. c + T <= M 이라면 운동을 해야 함.
	// 2. 운동을 할 수 없다면 휴식을 해야 함. 
	// 3. c - R < m 이라면 c = m이다.
	// 4. 운동을 할 수 없는 경우는 m + T > M 인 경우임.
	if (m + T > M)
		cout << -1;
	else {
		while (e != N) {
			if (c + T <= M) {
				c += T;
				t++;
				e++;
			}
			else {
				if (c - R < m) {
					c = m;
					t++;
				}
				else {
					c -= R;
					t++;
				}
			}
		}

		cout << t;
	}

}