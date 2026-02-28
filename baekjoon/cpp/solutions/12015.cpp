#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000];
vector<int> who; // dp[i]의 값 중 가장 작은 수 저장

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0;i < n;i++) {
		// 현재 원소가 LIS의 마지막 원소보다 더 큼
		int lower= lower_bound(who.begin(), who.end(), v[i]) - who.begin();

		if (lower == who.size()) {
			who.push_back(v[i]);
		}
		else {
			who[lower] = v[i];
		}
	}

	cout << who.size();
}