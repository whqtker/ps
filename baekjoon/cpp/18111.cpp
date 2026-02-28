#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> coor;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		coor.push_back(x);
	}

	vector<int> h = coor; // h: 입력받은 높이를 정렬하고 중복값을 제거한 값이 들어있음
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());

	vector<int> time; // 걸린 시간을 저장하는 벡터
	sort(coor.rbegin(), coor.rend()); // 내림차순으로 정렬한다. 높이가 높은 블록부터 정리해야 여분 블록을 챙길 수 있다.
	for (int i = h[0]; i <= h[h.size() - 1]; i++) {
		int inventory = b; // 현재 인벤토리에 있는 블록
		int cnt = 0; // 블록을 쌓는 데 사용한 횟수
		int t = 0; // 걸린 시간
		for (int j = 0; j < coor.size(); j++) {
			// 목표 높이가 현재 높이보다 클 때 - 블록을 쌓는다.
			if (i > coor[j]) {
				// 만약 쌓을 블록이 없을 때
				if (i - coor[j] > inventory - cnt) {
					t = -1;
					break;
				}
				else {
					t += i - coor[j];
					cnt += i - coor[j];
				}
			}
			// 목표 높이가 현재 높이보다 낮을 때  - 블록을 제거한다.
			else if (i < coor[j]) {
				t += 2 * (coor[j] - i);
				inventory += coor[j] - i;
			}
		}
		time.push_back(t); // t가 -1인 경우 만들 수 없는 경우이다(쌓을 블록이 부족한 경우).
	}

	int min = time[0];
	int minIdx = 0;
	for (int i = 0; i < time.size(); i++) {
		if (time[i] != -1 && min >= time[i]) {
			min = time[i];
			minIdx = i;
		}
	}

	cout << min << " " << h[0] + minIdx;
}