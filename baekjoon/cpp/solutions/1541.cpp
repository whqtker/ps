#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    int tmp = 0;
    int idx = 0;
    bool minus = false;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (minus) {
                tmp += stoi(s.substr(idx, i - idx));
            }
            else {
                ans += stoi(s.substr(idx, i - idx));
            }

            if (s[i] == '-') {
                minus = true;
            }

            idx = i + 1;
        }
    }

    cout << ans - tmp;
    return 0;
}
