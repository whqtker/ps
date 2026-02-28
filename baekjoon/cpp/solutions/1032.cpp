#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int fileCount; //파일의 개수, 50개 이하
	cin >> fileCount;

	vector<string>fileName(fileCount);

	for (auto& ele : fileName) //fileName 입력받기
	{
		cin >> ele;
	}

	//fileName들에서의 최대 길이 구하기
	int FileNameLength = fileName[0].size(); //파일 각각 이름들의 길이는 모두 같다

	vector<char> outputMessage; //출력될 메세지
	for (int i = 0; i < FileNameLength; i++)
	{
		bool flag = true;
		for (int j = 0; j < fileName.size() - 1; j++)
		{
			if (fileName[j][i] != fileName[j + 1][i])
			{
				outputMessage.push_back('?');
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			outputMessage.push_back(fileName[0][i]);
		}
	}

	for (auto& ele : outputMessage) //출력될 메세지 출력
	{
		cout << ele;
	}
}