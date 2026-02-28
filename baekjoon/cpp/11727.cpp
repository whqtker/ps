#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);

	for (int i = 3;i <= n;i++) {
		v.push_back((v[i - 1] + 2 * v[i - 2]) % 10007);
	}
	cout << v[n];
}