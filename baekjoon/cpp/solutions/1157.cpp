#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int howManyAlpha[26] = {}; //index가 0이면 a(97) 또는 A(65), index가 25면 z(122) 또는 Z(90), 0이면 존재 안함, 개수를 저장함, 0으로 초기화
	string word;
	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if (int(word.at(i)) >= 97)
			howManyAlpha[int(word.at(i)) - 97]++; //소문자
		else if (int(word.at(i)) <= 90)
			howManyAlpha[int(word.at(i)) - 65]++; //대문자
	}

	int maxValue = -1;
	int maxIndex;
	for (int i = 0; i < 26; i++) //최댓값 구하기
	{
		if (howManyAlpha[i] > maxValue)
		{
			maxValue = howManyAlpha[i];
			maxIndex = i;
		}
	}

	int howManyMax = 0;
	for (int i = 0; i < 26; i++) //최댓값이 어려 개 있는지 확인하기
	{
		if (howManyAlpha[i] == maxValue)
			howManyMax++;
	}

	if (howManyMax == 1)
		cout << char(maxIndex + 65);
	else if (howManyMax > 1)
		cout << '?';
}