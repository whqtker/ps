#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // 벡터 a, b의 크기
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	// b[p[i]] = a[i]이고 b는 비내림차순(해당 원소가 앞에 있는 원소보다 크거나 같음)
	// a를 sort한 결과의 원소의 원래 인덱스가 p이다.
	vector<int> sorted = a;
	sort(sorted.begin(), sorted.end());

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sorted[i] == a[j]) {
				p[j] = i;
				a[j] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
}