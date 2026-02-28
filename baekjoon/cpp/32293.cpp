#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<char> v;
        for (char c : s) {
            v.push_back(c);
        }

        int i = 0;
        while (i + 2 < v.size()) {
            if (v[i] == 'A' && v[i + 1] == 'B' && v[i + 2] == 'B') {
                v[i] = 'B';
                v[i + 1] = 'A';
                v.erase(v.begin() + i + 2);
                i = max(i - 2, 0);
            }
            else {
                i++;
            }
        }

        cout<< string(v.begin(), v.end());
    }
}
