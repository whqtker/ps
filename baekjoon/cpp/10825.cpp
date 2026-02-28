#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
	if (stoi(a[1]) != stoi(b[1]))
		return stoi(a[1]) > stoi(b[1]);

	if (stoi(a[2]) != stoi(b[2]))
		return stoi(a[2]) < stoi(b[2]);

	if (stoi(a[3]) != stoi(b[3]))
		return stoi(a[3]) > stoi(b[3]);

	return a[0] < b[0];
}

int main() {
	int n;
	cin >> n;

	vector<vector<string>> v(n);
	for (int i = 0;i < n;i++) {
		string q, w, e, r;
		cin >> q >> w >> e >> r;
		v[i].push_back(q);
		v[i].push_back(w);
		v[i].push_back(e);
		v[i].push_back(r);
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0;i < n;i++)
		cout << v[i][0] << "\n";
}