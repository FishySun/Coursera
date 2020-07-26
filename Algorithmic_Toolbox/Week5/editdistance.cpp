/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;

int editdistance(const string a, const string b) {
	size_t m = a.length();
	size_t n = b.length();
	vector <vector <int>> dp(m+1, vector <int> (n+1));
	for (size_t i=0; i<=m; ++i) {
		for (size_t j=0; j<=n; ++j) {
			if (!i) dp[i][j] = j;
			else if (!j) dp[i][j] = i;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = 1 + std::min(dp[i][j-1],std::min(dp[i-1][j], dp[i-1][j-1]));
			}
		}
	}
	return dp[m][n];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << editdistance(a, b) << '\n';
}
