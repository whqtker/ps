#include <iostream>

using namespace std;

int n, m;
int visited[9];
int arr[9];

void bt(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[k] = i;
			bt(k + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	bt(0);
}