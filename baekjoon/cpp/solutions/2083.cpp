#include <iostream>

using namespace std;

int main() {
	string name, grade;
	int age, weight;

	while (1) {
		cin >> name >> age >> weight;
		if (name == "#" && age == 0 && weight == 0) break;
		else {
			if (age > 17 || weight >= 80) grade = "Senior";
			else grade = "Junior";

			cout << name << " " << grade << "\n";
		}

	}
}