#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<string>> info(201); // 인덱스는 나이를 의미하고 원소는 이름이다.
	for (int i = 0; i < n; i++) {
		int age;
		cin >> age;
		string name;
		cin >> name;
		info[age].push_back(name);
	}

	for (int i = 0; i < info.size(); i++) {
		if (info[i].size() != 0) {
			for (int j = 0; j < info[i].size(); j++) {
				cout << i << " " << info[i][j] << "\n";
			}
		}
	}
}