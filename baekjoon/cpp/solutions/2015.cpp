#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cumsum = 0;
	long long cnt = 0;
	map<int, int> m;
	m[0] = 1; // 자기 자신이 k인 경우

	for (int i = 0; i < n; i++) {
		cumsum += v[i];
		cnt += m[cumsum - k];
		m[cumsum]++;
	}

	cout << cnt;
}