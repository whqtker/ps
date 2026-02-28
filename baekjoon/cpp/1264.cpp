#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	while (1) {
		int cnt = 0;

		getline(cin, str);

		if (str == "#") break;
		else {
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
					cnt++;
			}
		}
		cout << cnt << "\n";
	}
}