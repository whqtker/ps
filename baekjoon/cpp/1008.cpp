#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setprecision;

int main() {

	int a, b;
	cin >> a >> b;
	cout << setprecision(32);
	cout << (double)a / (double)b;
}