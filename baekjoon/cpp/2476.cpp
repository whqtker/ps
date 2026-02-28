#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // 참가한 사람의 수
	vector<int> tot; // 각 참가자가 받은 상금

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> dice; // 주사위의 눈금
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			dice.push_back(a);
		}

		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[0])
			tot.push_back(dice[0] * 1000 + 10000);
		else if (dice[0] == dice[1])
			tot.push_back(dice[0] * 100 + 1000);
		else if (dice[1] == dice[2])
			tot.push_back(dice[1] * 100 + 1000);
		else if (dice[2] == dice[0])
			tot.push_back(dice[2] * 100 + 1000);
		else
			tot.push_back(*max_element(dice.begin(), dice.end()) * 100); // max()는 최댓값의 iter를 반환함.
	}

	cout << *max_element(tot.begin(), tot.end());
}