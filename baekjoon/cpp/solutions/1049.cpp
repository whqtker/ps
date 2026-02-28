#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; //끊어진 n개의 줄, 기타줄 브랜드 m개, m개의 패키지(6개가 들어있음) 가격과 낱개 가격이 주어진다.
	cin >> n >> m;

	vector<int> bundle;
	vector<int> piece;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		bundle.push_back(x);
		piece.push_back(y);
	}

	//낱개 * 6 가격이 패키지 가격보다 싸거나 같은 경우
	if (*min_element(bundle.begin(), bundle.end()) >= *min_element(piece.begin(), piece.end()) * 6) {
		cout << *min_element(piece.begin(), piece.end()) * n;
	}
	else {
		cout << *min_element(bundle.begin(), bundle.end()) * (n / 6) + min(*min_element(piece.begin(), piece.end()) * (n % 6), *min_element(bundle.begin(), bundle.end()));
	}
}