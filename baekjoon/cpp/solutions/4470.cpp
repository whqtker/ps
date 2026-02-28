#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string str;
	
	vector<string> sentences;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		sentences.push_back(str);
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << sentences[i] << "\n";
	}
}