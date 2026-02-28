#include <iostream>

using namespace std;

int main() {
	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	if (a * n + b == c * n + d)
		cout << "Yes " << a * n + b;
	else
		cout << "No";
}