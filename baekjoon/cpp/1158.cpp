#include <iostream>
#include <queue>

using std::cout;
using std::cin;

int main()
{
	int n, k; //총 n명의 사람들, k번째 사람 제거, k <= n
	cin >> n >> k;

	std::queue<int> people;
	for (int i = 1; i <= n; i++) //큐 people에 1부터 n까지 수 넣기
	{
		people.push(i);
	}

	cout << "<";
	while (people.empty() == false) //큐가 다 빌 때까지 while문 진행
	{
		for (int i = 0; i < k - 1; i++)
		{
			people.push(people.front());
			people.pop();
		}
		cout << people.front();
		if (people.size() != 1)
			cout << ", ";
		people.pop();
	}
	cout << ">";
}