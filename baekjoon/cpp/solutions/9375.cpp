#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		multimap<string, string> mm;
		map<string, string>m; // 중복이 제거된 key값(옷의 종류)만 있음
		for (int j = 0; j < n; j++) {
			string name;
			string type;
			cin >> name >> type;
			m[type] = name;
			mm.insert({ type,name });
		}

		int cnt = 1;
		for (auto it : m) {
			cnt *= (mm.count(it.first) + 1);
		}
		cout << cnt - 1 << "\n"; // 안 입는 경우 제외
	}
}