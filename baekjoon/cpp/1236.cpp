#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> v;
	int rowCnt = 0;
	int colCnt = 0;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(s);

		// 경비원이 없다면
		if (s.find('X') == string::npos)rowCnt++;
	}

	for (int i = 0;i < m;i++) {
		string s = "";
		for (int j = 0;j < n;j++) {
			s.push_back(v[j][i]);
		}
		// 경비원이 없다면
		if (s.find('X') == string::npos)colCnt++;
	}

	cout << max(rowCnt, colCnt);
}