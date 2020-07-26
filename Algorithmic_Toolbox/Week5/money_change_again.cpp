/* Author: Prasun Biswas */
#include <iostream>
using std::cin;
using std::cout;
using std::min;

int moneychange(const int &n, const int *a) {
	int dp[n+1];
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<3; ++j) {
			if (i-a[j] >= 0) {
				dp[i] = min(dp[i-a[j]]+1, dp[i]);
			}
		}
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int coins[] = {1, 3, 4};
	cout << moneychange(n, coins) << '\n';
}
