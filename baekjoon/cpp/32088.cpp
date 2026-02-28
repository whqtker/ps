#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long arr[200000];

// k개의 삼각형을 만들 수 있는지
// 각 변에서 min(arr[i], k)개의 점들을 취한다.
bool check(long long k) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(arr[i], 2 * k);
    }
    return sum >= 3 * k; // 삼각형 k개를 만드는 데 필요한 점의 수는 최소 3k개
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long total = 0; // 총 점의 수

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    long long low = 0, high = total / 3, answer = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer;
}
