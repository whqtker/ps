#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string color[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };

	string firstColor, secondColor, thirdColor;
	cin >> firstColor >> secondColor >> thirdColor;

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		if (color[i] == firstColor) {
			result += i * 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (color[i] == secondColor) {
			result += i;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (color[i] == thirdColor) {
			result *= pow(10, i);
		}
	}

	cout << result;
}