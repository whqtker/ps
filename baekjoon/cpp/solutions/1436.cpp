#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num = 666;
	int seq = 1;

	while (seq != n) {
		num++;
		int tmp = num;
		bool flag = false;
		while (tmp != 0) {
			if (tmp % 1000 == 666)
				flag = true;
			tmp /= 10;
		}

		if (flag == true)
			seq++;
	}

	cout << num;
}