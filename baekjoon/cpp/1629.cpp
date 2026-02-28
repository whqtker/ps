#include <iostream>

using namespace std;

long long recur(long long a, long long b, long long c) {
	if (b == 0)
		return 1;
	if (b == 1) 
		return a % c;
	
	else if (b % 2 == 0)
		return (recur(a, b / 2, c) * recur(a, b / 2, c)) % c;
	else if (b % 2 == 1)
		return (recur(a, b / 2, c) * recur(a, b / 2 + 1, c)) % c;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	cout << recur(a, b, c) % c;
}