#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void postorder(int s, int e) {
	if (s >= e)
		return;

	// 서브트리의 리프 노드 출력
	if (s == e - 1) {
		cout << v[s] << "\n";
		return;
	}

	int i = s + 1;
	// 루트 노드보다 더 큰 값의 인덱스를 찾는다.
	while (i < e) {
		if (v[s] < v[i])
			break;
		i++;
	}

	// 왼쪽 서브트리 순회
	postorder(s + 1, i);

	// 오른쪽 서브트리 순회
	postorder(i, e);

	// 서브트리의 루트 노드 출력
	cout << v[s] << "\n";
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	// 루트 노드보다 작은 값들은 왼쪽 서브트리, 큰 값들은 오른쪽 서브트리이다.
	postorder(0, v.size());
}