#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;
	getline(cin, sentence);

	int blankCnt = 0;
	for (int i = 0; i < sentence.size(); i++)
	{
		if (i == 0 || i == sentence.size() - 1) //문장의 맨 앞과 뒤는 단어 개수에 영향을 주지 않으므로 넘어간다. 설령 해당 index가 가리키는 것이 알파벳 또는 공백일지라도
			continue;

		if (sentence[i] == ' ')
			blankCnt++;

	}
	int wordCnt = blankCnt + 1;
	if (sentence.size() == 1 && sentence == " ") //예외 처리 부분
		wordCnt = 0;

	cout << wordCnt;
}