#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;
int n;

vector<int> recur(int startInorder, int endInorder, int startPostorder, int endPostorder) {
	if (startInorder > endInorder || startPostorder > endPostorder) {
		return {};
	}

	// 루트 노드는 postorder의 마지막 원소
	int root = postorder[endPostorder];
	int inorderRootIndex = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// 왼쪽 서브트리의 크기
	int leftTreeSize = inorderRootIndex - startInorder;

	vector<int> preorder;
	preorder.push_back(root);

	// 왼쪽 서브트리
	vector<int> leftPreorder = recur(startInorder, inorderRootIndex - 1, startPostorder, startPostorder + leftTreeSize - 1);

	// 오른쪽 서브트리
	vector<int> rightPreorder = recur(inorderRootIndex + 1, endInorder, startPostorder + leftTreeSize, endPostorder - 1);

	preorder.insert(preorder.end(), leftPreorder.begin(), leftPreorder.end());
	preorder.insert(preorder.end(), rightPreorder.begin(), rightPreorder.end());

	return preorder;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		inorder.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		postorder.push_back(x);
	}


	vector<int> preorder = recur(0, n - 1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << preorder[i] << " ";
	}
}