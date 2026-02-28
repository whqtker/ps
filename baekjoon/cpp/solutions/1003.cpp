#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int firstZero = 1;
		int firstOne = 0;
		int secondZero = 0;
		int secondOne = 1;
		int zeroCnt, oneCnt;

		int n;
		cin >> n;

		if (n == 0) {
			zeroCnt = firstZero;
			oneCnt = firstOne;
		}
		else if (n == 1) {
			zeroCnt = secondZero;
			oneCnt = secondOne;
		}
		else {
			for (int j = 2; j <= n; j++) {
				zeroCnt = firstZero + secondZero;
				firstZero = secondZero;
				secondZero = zeroCnt;

				oneCnt = firstOne + secondOne;
				firstOne = secondOne;
				secondOne = oneCnt;
			}
		}

		cout << zeroCnt << " " << oneCnt << "\n";
	}
}