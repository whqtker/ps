#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[50001]; // dp[i]: i원을 만들 수 있는가?

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int idx = 0; idx < 3; idx++) {
        int n;
        cin >> n;

        vector<pair<int, int>> coins(n); // 동전들 (무게, 개수)
        int amount = 0;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            coins[i] = { a, b };
            amount += a * b;
        }

        // 총합이 홀수면 어차피 안 됨
        if (amount % 2 == 1) {
            cout << "0\n";
            continue;
        }
        amount /= 2; // 가진 동전들로 amount를 만들 수 있다면 절반씩 분배 가능

        // dp 초기화
        fill(dp, dp + amount + 1, 0);
        dp[0] = 1; // 0원을 만드는 경우

        for (auto coin : coins) {
            int value = coin.first; // 동전의 금액
            int count = coin.second; // 동전의 개수

            for (int j = amount; j >= value; j--) {
                // 현재 동전을 사용할 수 있는 만큼 반복
                for (int k = 1; k <= count && j >= k * value; k++) {
                    // j원을 만들 수 있는 경우
                    if (dp[j - k * value]) {
                        dp[j] = 1;
                        break; // 한 번이라도 j원을 만들 수 있다면 더 이상 k를 증가시킬 필요 없음
                    }
                }
            }
        }

        cout << dp[amount] << "\n";
    }
}
