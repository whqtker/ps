#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, l, d; // n: 노래 곡 수, l: 각 노래의 길이, d: 전화벨의 간격
	cin >> n >> l >> d;

	vector<int> album, ring; // 앨범과 전화벨의 시간(인덱스)에 따라 전화벨을 들을 수 있는지, 또는 전화벨이 울리는 지 여부를 저장하는 벡터
	
	// 들을 수 없는 상태이거나 전화벨이 울리지 않는다면 0, 들을 수 있거나 울린다면 1을 저장한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			album.push_back(0);
		}
		if (i != n - 1) {
			for (int j = 0; j < 5; j++) {
				album.push_back(1);
			}
		}
	}

	while (1) {
		ring.push_back(1);
		if (ring.size() == album.size()) break;

		// 전화벨이 울린 시점부터 d초 후 다시 울리므로 울리지 않는 시간은 d - 1초이다.
		bool flag = true;
		for (int i = 0; i < d - 1; i++) { 
			ring.push_back(0);
			if (ring.size() == album.size()) {
				flag = false;
				break;
			}
		}
		if (flag == false) break;
	}

	int t = -1;
	for (int i = 0; i < album.size(); i++) {
		if (album[i] == 1 && ring[i] == 1) {
			t = i;
			break;
		}
	}

	// t == -1 이라는 것은 노래가 끝날 때까지 겹치는 구간이 없었다는 것이다.
	if (t == -1) {
		int i = 0;
		while (i * d <= album.size() - 1) {
			t = i * d;
			i++;
		}
		t = i * d;
	}

	cout << t;
}