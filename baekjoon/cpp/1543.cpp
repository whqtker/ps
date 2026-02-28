#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	string find;
	getline(cin, find);

	int cnt = 0;
	int idx = 0;
	while (str.find(find, idx) != string::npos) {
		// find()는 찾은 원소들의 첫 번째 인덱스를 반환함.
		idx = str.find(find, idx) + find.length();
		cnt++;
	}

	cout << cnt;
}