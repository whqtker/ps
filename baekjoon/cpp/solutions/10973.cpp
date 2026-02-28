#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	vector<int> rest;
	bool flag = false;
	for (int i = n - 1;i > 0;i--) {
		if (v[i - 1] > v[i]) {
			flag = true;
			rest.push_back(v[i - 1]);
			for (int j = 0;j < i - 1;j++) {
				cout << v[j] << " ";
			}

			int tmp = 0;
			for (int j = i;j < n;j++) {
				if (v[i - 1] > v[j] && v[j] > tmp)
					tmp = v[j];
			}
			cout << tmp << " ";

			for (int j = i;j < n;j++) {
				if (v[j] != tmp)
					rest.push_back(v[j]);
			}
			sort(rest.begin(), rest.end(), greater<>());

			for (int j = 0;j < rest.size();j++) {
				cout << rest[j] << " ";
			}
			break;
		}
	}
	if (flag == false)
		cout << -1;
}