#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		nums.push_back(n);
	}

	sort(nums.begin(), nums.end());
	int mul = nums[2];

	while (1) {
		int divided, notDivided;
		divided = notDivided = 0;
		for (int i = 0; i < 5; i++) {
			if (mul % nums[i] == 0)
				divided++;
			else
				notDivided++;
		}

		if (divided >= 3)
			break;
		else
			mul++;
	}

	cout << mul;
}