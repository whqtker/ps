#include <iostream>

using std::cout;
using std::cin;

int main() {
	const int max_sub_cnt = 1000;
	double score[max_sub_cnt] = {};
	int sub_cnt;

	cin >> sub_cnt;

	for (int i = 0; i < sub_cnt; i++)
	{
		cin >> score[i];
	}

	double MaxScore = 0;
	for (int i = 0; i < sub_cnt; i++)
	{
		if (score[i] >= MaxScore)
		{
			MaxScore = score[i];
		}
	}

	double tot = 0;
	double avg;
	for (int i = 0; i < sub_cnt; i++)
	{
		score[i] = (score[i] / MaxScore) * 100.0; //최고 점수가 아닌 다른 과목의 점수 재설정
		tot += score[i];
	}

	avg = tot / sub_cnt;
	cout << std::fixed; //소수점 밑 자리수 고정.
	cout.precision(3); //소수점 밑 3자리로 고정, 위 코드와 상호작용
	cout << avg;

	return 0;
}