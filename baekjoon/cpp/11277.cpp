#include <iostream>

using namespace std;

int n, m;
pair<int, int> clauses[100]; // clause 저장
bool tmp[21]; // x_n의 값
int ans;

void bt(int k) {
	if (k == n + 1) {
		bool flag = true;

		for (int i = 0;i < m;i++) {
			bool a, b;

			if (clauses[i].first < 0)
				a = !tmp[-clauses[i].first];
			else
				a = tmp[clauses[i].first];

			if (clauses[i].second < 0)
				b = !tmp[-clauses[i].second];
			else
				b = tmp[clauses[i].second];

			if ((a || b) == false)
				flag = false;
		}

		if (flag) {
			ans = 1;
		}

		return;
	}

	tmp[k] = true;
	bt(k + 1);

	tmp[k] = false;
	bt(k + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> clauses[i].first >> clauses[i].second;
	}

	bt(1);
	cout << ans;
}