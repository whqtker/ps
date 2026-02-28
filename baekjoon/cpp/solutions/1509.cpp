#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int dp[2501]; // dp[i]: i번 째까지 분할된 팰린드롬의 최솟값

bool isPalindrome(int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    cin >> s;
    
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int minCuts = i + 1; // 최대 i + 1번 분할 가능
        for (int j = 0; j <= i; j++) {
            if (isPalindrome(j, i)) {
                // j부터 i까지 하나의 팰린드롬임. 이때 i까지 최소 팰린드롬의 수는 dp[j - 1] + 1이 될 수 있음.
                // 만약 처음부터 하나의 팰린드롬이라면 1로 간주
                minCuts = (j == 0) ? 1 : min(minCuts, dp[j - 1] + 1);
            }
        }
        dp[i] = minCuts;
    }

    cout << dp[n - 1];
}