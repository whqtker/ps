#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int s;
		cin >> s;

		vector<int> shop;
		int sum = 0;
		for (int j = 0; j < s; j++) {
			int d;
			cin >> d;
			shop.push_back(d);
		}

		// 최단거리는 항상 좌표가 가장 큰 지점과 작은 지점의 거리의 두 배이다.
		// 가게를 갈 때 어떤 가게를 지나서 가는 경우는 최단거리가 아니다.
		sort(shop.begin(), shop.end());
		cout << (shop[shop.size() - 1] - shop[0]) * 2 << "\n";
	}
}