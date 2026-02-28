#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k, n; // k개의 가지고 있는 랜선의 수, n개의 만들어야 하는 랜선의 개수
	cin >> k >> n;
	vector<int> lan; // 가지고 있는 랜선의 길이를 저장하는 벡터
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		lan.push_back(x);
	}

	sort(lan.begin(), lan.end());
	long long int left = 1;
	long long int right = lan[lan.size() - 1];

	while (left <= right) {
		long long int mid = left + (right - left) / 2; // 오버플로우 방지
		long long int sum = 0; // 잘린 랜선의 개수
		for (int i = 0; i < lan.size(); i++) {
			sum += lan[i] / mid;
			if (sum >= n) break; // sum이 n 보다 크면 굳이 이 과정을 수행할 필요가 없다. 오버플로우 방지를 위해 반복문을 나간다.
		}

		if (sum >= n) {
			left = mid + 1;
		}
		else if (sum < n) {
			right = mid - 1;
		}
	}
	cout << right; // left와 right가 같을 때 while문을 빠져나오기 때문에 right가 최대 랜선의 길이가 됨

}