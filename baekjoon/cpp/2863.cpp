#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	double a, b, c, d; // 0회전: a/c+b/d, 1회전: c/d+a/b, 2회전: d/b+c/a, 3회전: b/a+d/c
	cin >> a >> b >> c >> d;

	vector<double> result;
	result.push_back(a / c + b / d);
	result.push_back(c / d + a / b);
	result.push_back(d / b + c / a);
	result.push_back(b / a + d / c);

	int maxIdx = max_element(result.begin(), result.end()) - result.begin(); // 최댓값의 인덱스를 구한다.
	cout << maxIdx;
}