#include <iostream>
#include <vector>

using namespace std;

int score[1000001];
int input[1000001];

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int max = 0;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		input[x] = 1;
		v.push_back(x);
		max = max < x ? x : max;
	}

	for (int i = 0;i < n;i++) {
		int mul = 2;
		int nxt = v[i] * mul;
		while (nxt <= max) {
			if (input[nxt]) {
				score[nxt]--;
				score[v[i]]++;
			}
			nxt = v[i] * ++mul;
		}
	}

	for (int i = 0;i < n;i++) {
		cout << score[v[i]] << " ";
	}
}