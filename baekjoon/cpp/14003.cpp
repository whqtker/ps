#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp; // LIS의 길이를 구하는 데 사용
int lis_idx[1000000];

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();

		if (idx == tmp.size()) {
			tmp.push_back(v[i]);
		}
		else {
			tmp[idx] = v[i];
		}

		lis_idx[i] = idx;
	}

	cout << tmp.size() << "\n";

	// LIS에 해당하는 수의 인덱스 역추적
	int cur = tmp.size() - 1;
	vector<int> rev_lis;
	for (int i = n - 1; i >= 0; i--) {
		if (lis_idx[i] == cur) {
			rev_lis.push_back(v[i]);
			cur--;
		}
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		cout << rev_lis[i] << " ";
	}
}