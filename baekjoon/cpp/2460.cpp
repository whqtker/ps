#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> total; // 최종 사람의 수
	for (int i = 0; i < 10; i++) {
		int a, b; // a: 내린 사람, b: 탄 사람
		cin >> a >> b;

		if (i == 0)
			total.push_back(b);
		else
			total.push_back(total[i - 1] - a + b);
	}

	cout << *max_element(total.begin(), total.end());
}