/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int solve(const vector <int> &a, const vector <int> &b) {
	vector <vector <int>> dp(a.size()+1, vector <int> (b.size()+1));
	for (size_t i=0; i<=a.size(); ++i) {
		for (size_t j=0; j<=b.size(); ++j) {
			if (!i || !j) dp[i][j] = 0;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[a.size()][b.size()];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; ++i) cin >> a[i];
	cin >> m;
	vector <int> b(m);
	for (int i=0; i<m; ++i) cin >> b[i];
	cout << solve(a, b) << '\n';
}
