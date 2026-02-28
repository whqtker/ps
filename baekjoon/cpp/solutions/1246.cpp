#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; // n개의 달걀, m개의 고객
	cin >> n >> m;

	vector<int> cost; // 고객이 희망하는 달걀의 가격. 달걀의 가격이 cost의 원소보다 작거나 같으면 구매.
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cost.push_back(x);
	}

	// 판매 가격이 최대가 되는 경우는 고객의 희망 가격과 동일할 때 형성됨.
	sort(cost.begin(), cost.end());

	vector<int> sell;
	for (int i = 0; i < m; i++) {
		if (n < m - i) {
			int s = cost[i] * n;
			sell.push_back(s);
		}
		else {
			int s = cost[i] * (m - i);
			sell.push_back(s);
		}
	}

	cout << cost[max_element(sell.begin(), sell.end()) - sell.begin()] << " " << *max_element(sell.begin(), sell.end());
}