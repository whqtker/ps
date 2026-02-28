#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	long long ans = 0;
	stack<pair<int, int>> s; // {키, 같은 키를 가진 사람의 수}
	for (int i = 0; i < n; i++) {
		// 현재 사람이 본인보다 키가 작은 사람이 있는지 확인하여 쌍을 이룬다.
		while (!s.empty() && s.top().first < v[i]) {
			ans += s.top().second;
			s.pop();
		}

		// 현재 사람에 대한 정보를 스택에 삽입한다.
		// 현재 사람에 대한 정보가 존재하는 경우
		if (!s.empty() && s.top().first == v[i]) {
			ans += s.top().second; // 키가 같은 사람들끼리의 쌍
			int cnt = s.top().second;
			s.pop();

			if (!s.empty()) ans++; // 스택에 존재하는 더 큰 사람과의 쌍
			s.push({ v[i], cnt + 1 });
		}
		// 현재 사람에 대한 정보가 존재하지 않는 경우
		else {
			if (!s.empty()) ans++;
			s.push({ v[i], 1 });
		}
	}

	cout << ans;
}