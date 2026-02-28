#include <iostream>
#include <algorithm>

using namespace std;

struct Ball {
	int color;
	int size;
	int idx;
};

Ball balls[200001];
int cumsumByColor[200001];
int cumsumBySize[2001];

int ans[200001];

bool cmp(Ball a, Ball b) {
	if (a.size == b.size)
		return a.color < b.color;
	return a.size < b.size;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> balls[i].color >> balls[i].size;
		balls[i].idx = i;
	}

	sort(balls, balls + n, cmp);

	// i번 째 공이 사로잡은 공의 크기: i번 째까지 모든 공의 크기의 합 
	// - i번 째 공과 색이 같은 공의 크기의 합(1) - i번 째 공과 크기가 같은 공의 크기의 합(2)
	// + i번 째 공의 크기(3) ((2)에서 불필요하게 빠진 무게 보정)
	int total = 0;
	for (int i = 0; i < n; i++) {
		int color = balls[i].color;
		int size = balls[i].size;
		int idx = balls[i].idx;

		total += size;
		cumsumByColor[color] += size;
		cumsumBySize[size] += size;

		// 현재 공이 중복된 공인 경우 이전 공의 정보를 가져온다.
		if (i - 1 >= 0 && balls[i - 1].color == color && balls[i - 1].size == size) {
			ans[idx] = ans[balls[i - 1].idx];
		}
		else
			ans[idx] = total - cumsumByColor[color] - cumsumBySize[size] + size;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}