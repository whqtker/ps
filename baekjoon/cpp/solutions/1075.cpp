#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int f; //n: 뒤의 두 자리를 적절히 바꿀 수, f: 바뀐 n을 나누어 떨어지게 하는 수
	cin >> n >> f;

	//int x = 0;
	//int tmp = n;
	//while (tmp > 0) //자리 수 구하는 함수
	//{
	//	tmp /= 10;
	//	x++;
	//}

	n -= ((n % (int)pow(10, 2)));

	int cnt = 0;
	while (n % f != 0)
	{
		n++;
		cnt++;
	}

	if (cnt < 10)
		cout << 0 << cnt;
	else
		cout << cnt;
}