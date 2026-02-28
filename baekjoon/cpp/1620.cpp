#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; // n: 현재 도감에 등록된 포켓몬 수, m: 문제의 수
	cin >> n >> m;

	map<string, int> pokemon1;
	map<int, string> pokemon2;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		pokemon1[x] = i + 1;
		pokemon2[i + 1] = x;
	}

	for (int i = 0; i < m; i++) {
		string prob;
		cin >> prob;
		// atoi(): 문자열이 숫자면 0 출력, c_str(): string -> const char* 로 변환
		// 입력받은 문자열이 포켓몬 이름이라면
		if (atoi(prob.c_str()) == 0) {
			cout << pokemon1.find(prob)->second << "\n";
		}
		else {
			cout << pokemon2.find(stoi(prob))->second << "\n";
		}
	}
}