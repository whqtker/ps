#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int FirstValue = min(w - x, h - y);
	int secondValue = min(x, y);
	cout << min(FirstValue, secondValue);
}