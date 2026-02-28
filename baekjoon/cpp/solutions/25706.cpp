#include <iostream>

using namespace std;

int dp[400001];
int jump[200001];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> jump[i];
	}

	for (int i = n; i >= 0; i--) {
		dp[i] = dp[i + jump[i] + 1] + 1;
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
}