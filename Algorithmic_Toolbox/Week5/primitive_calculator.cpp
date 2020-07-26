/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
#include <climits>
using std::cin;
using std::cout;
using std::vector;
using std::min;

vector <int> backtrack(const vector <int> &ans, int &n) {
	vector <int> sol;
	while (n > 0) {
		sol.emplace_back(n);
		if (n%2 != 0 and n%3 != 0) --n;
		else if (n%2 ==0 and n%3 ==0) n /= 3;
		else if (n%2 == 0) {
			if (ans[n-1] > ans[n/2]) n/=2;
			else --n;
		}
		else if (n%3 == 0) {
			if (ans[n-1] > ans[n/3]) n /= 3;
			else --n;
		}
	}
	return sol;
}

vector <int> solve(const int &n) {
	vector <int> ss(n+1);
	std::fill(ss.begin(), ss.end(), 0);
	for (int i=2; i<=n; ++i) {
		int m1 = ss[i-1];
		int m2 = INT_MAX;
		int m3 = INT_MAX;
		if (i%2 == 0) m2 = ss[i/2];
		if (i%3 == 0) m3 = ss[i/3];
		ss[i] = 1 + min(m1, min(m2, m3));
	}
	return ss;
}

vector <int> primitive_calc (const int &n) {
	vector <int> ans;
	if (n == 1) {
		ans.emplace_back(1);
		return ans;
	}
	ans = solve(n);
	return backtrack(ans, n);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> ans = primitive_calc(n);
	cout << ans.size() - 1 << '\n';
	for (auto it=ans.rbegin(); it!=ans.rend(); ++it) cout << *it << ' ';
	cout << '\n';
}
