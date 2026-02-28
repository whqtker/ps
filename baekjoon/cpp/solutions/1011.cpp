#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int departure, arrival;
		cin >> departure >> arrival;
		int distance = arrival - departure; //두 점 사이 거리

		if (distance == 1)
			cout << 1 << "\n";
		else if (distance == 2)
			cout << 2 << "\n";
		else if (distance == 3)
			cout << 3 << "\n";
		else {
			double squared = sqrt(distance);
			if (squared == (int)squared) {
				cout << (int)squared * 2 - 1 << "\n";
			}
			else {
				int middle = pow((int)squared, 2) + (pow((int)squared + 1, 2) - pow((int)squared, 2)) / 2;

				if (middle >= distance)
					cout << (int)squared * 2 << "\n";
				else
					cout << (int)squared * 2 + 1 << "\n";
			}
		}
	}
}