#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string ops;
		cin >> ops;

		int n;
		cin >> n;

		string arr;
		cin >> arr;

		deque<int> dq;
		string num = "";
		for (int i = 1; i < arr.length(); i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				num += arr[i];
			}
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!num.empty()) {
					dq.push_back(stoi(num));
					num = "";
				}
			}
		}

		bool reverse_flag = false;
		bool error_flag = false;

		for (auto op : ops) {
			if (op == 'R')
				reverse_flag = !reverse_flag;
			else if (op == 'D') {
				if (dq.empty()) {
					error_flag = true;
					break;
				}

				if (reverse_flag)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		if (error_flag)
			cout << "error\n";
		else {
			cout << '[';
			if (reverse_flag) {
				for (auto iter = dq.rbegin(); iter != dq.rend();iter++) {
					cout << *iter;
					if (iter + 1 != dq.rend()) cout << ",";
				}
			}
			else {
				for (auto iter = dq.begin(); iter != dq.end(); iter++) {
					cout << *iter;
					if (iter + 1 != dq.end()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}