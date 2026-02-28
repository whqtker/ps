#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int whiteCnt = 0, blueCnt = 0;

void ans(vector<int> v) {
	int s = sqrt(v.size()); // v의 한 변의 길이
	vector<int> white(pow(s, 2), 0);
	vector<int> blue(pow(s, 2), 1);

	if (v == white) {
		whiteCnt++;
	}
	else if (v == blue) {
		blueCnt++;
	}

	// v가 기준과 다르다면 분할 정복 실시
	else {
		// I 구역
		vector<int> one;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				one.push_back(v[i * s + j]);
			}
		}
		ans(one);

		// II 구역
		vector<int> two;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				two.push_back(v[i * s + j + s / 2]);
			}
		}
		ans(two);

		// III 구역
		vector<int> three;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				three.push_back(v[(i + s / 2) * s + j]);
			}
		}
		ans(three);

		// IV 구역
		vector<int> four;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				four.push_back(v[(i + s / 2) * s + j + s / 2]);
			}
		}
		ans(four);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	ans(v);
	cout << whiteCnt << " " << blueCnt;
}