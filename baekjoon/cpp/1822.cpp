#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	map<int, int> m1, m2;
	for (int i = 0;i < a;i++) {
		int x;
		cin >> x;
		m1[x] = i;
	}

	for (int i = 0;i < b;i++) {
		int x;
		cin >> x;
		m2[x] = i;
	}

	vector<int> v;
	for (auto iter : m1) {
		// m1에는 있고 m2에는 없다면
		if (m2.find(iter.first) == m2.end()) {
			v.push_back(iter.first);
		}
	}
	
	cout << v.size() << "\n";
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
}