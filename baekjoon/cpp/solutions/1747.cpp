#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < 1004000; i++) {
		nums.push_back(i); //0~1000000까지
	}

	for (int i = 2; i < 1004000; i++) { //에라토스테네스의 체
		if (nums[i] == 0)
			continue;

		if ((unsigned int)pow(nums[i], 2) > 1004000)
			break;
		else {
			for (int j = pow(nums[i], 2); j < 1004000; j += nums[i]) {
				nums[j] = 0;
			}
		}
	}

	for (int i = n; i < 1004000; i++) {
		if (nums[i] == 0 || nums[i] == 1)
			continue;
		else {
			int tmp = nums[i];
			string numStr = to_string(tmp);
			string reversed;
			if (to_string(tmp).size() > 1) {
				reverse(numStr.begin(), numStr.end());
				reversed = numStr;
			}
			else
				reversed = numStr;

			if (to_string(nums[i]) == reversed) {
				cout << nums[i];
				break;
			}
		}
	}
}