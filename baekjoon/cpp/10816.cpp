#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// upper_bound: 찾으려는 값보다 큰 값의 iter를 반환함.
	// lower_bound: 찾으려는 값과 같거나 큰 값의 iter를 반환함.
	// 단, 오름차순으로 정렬되어야 한다.

	vector<int> card;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		card.push_back(x);
	}

	sort(card.begin(), card.end());

	vector<int> find;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		find.push_back(x);
	}

	// a 이상 b 이하인 수의 개수를 구하는 코드는 다음과 같이 작성한다.
	// upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a)
	for (int i = 0; i < m; i++) {
		cout << upper_bound(card.begin(), card.end(), find[i]) - lower_bound(card.begin(), card.end(), find[i]) << " ";
	}
}