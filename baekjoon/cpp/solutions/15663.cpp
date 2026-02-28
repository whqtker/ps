#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int input[8];
int visited[8];

void bt(int k) {
	if (m == k) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0;i < n;i++) {
		int x = input[i];
		if (!visited[i] && prev != x) {
			visited[i] = 1;
			arr[k] = x;
			prev = x;
			bt(k + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0;i < n;i++)
		cin >> input[i];

	sort(input, input + n);
	bt(0);
}