#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	// 점화식은 파보나치 수열과 동일하다.
	vector<int> v;
	v.push_back(0); // 인덱스와 n을 맞추기 위한 수
	v.push_back(1);
	v.push_back(2);

	for (int i = 3; i <= n; i++)
		v.push_back((v[i - 1] + v[i - 2]) % 10007);
	cout << v[n];
}