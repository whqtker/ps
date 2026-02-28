#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m; // n개의 저장된 사이트, m개의 찾으려는 사이트
	cin >> n >> m;
	map<string, string> site;

	for (int i = 0; i < n; i++) {
		string s, pw;
		cin >> s >> pw;
		site[s] = pw;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << site.find(s)->second << "\n";
	}
}