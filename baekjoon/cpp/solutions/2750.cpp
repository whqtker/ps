#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	//const int max_len = 1000;
	//int arr[max_len] = {};

	//int arr_len;
	//cin >> arr_len;

	//for (int i = 0; i < arr_len; i++)
	//{
	//	cin >> arr[i];
	//}

	//for (int i = 0; i < arr_len - 1; i++) // 버블 정렬
	//{
	//	for (int j = 0; j < arr_len - 1 - i; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			int temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//	}
	//}

	//for (int i = 0; i < arr_len; i++)
	//{
	//	cout << arr[i] << "\n";
	//}

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) {
		cout << v[i] << "\n";
	}
}