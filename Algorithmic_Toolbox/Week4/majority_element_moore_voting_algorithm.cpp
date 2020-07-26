/* Author: Prasun Biswas 
   This is implementation based on the Moore Voting Algorithm and this works in O(n) time */

#include <bits/stdc++.h>
using namespace std;

long long findCandidate(const vector <long long> &a) {
	int maj_index = 0, count = 1;
	for (auto i = a.begin(); i != a.end(); ++i) {
		if (a[maj_index] == *i) ++count;
		else --count;
		if (!count) {
			maj_index = i-a.begin();
			count = 1;
		}
	}
	return a[maj_index];
}

void solve(const vector <long long> &a, int n) {
	long long candidate = findCandidate(a);
	int count = 0;
	for (auto i = a.begin(); i!=a.end(); ++i) {
		if (*i == candidate) ++count;
		if (count > n) {
			cout << "1\n";
			exit(0);
		}
	}
	cout << "0\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <long long> a(n);
	for (long long &i : a) cin >> i;
	n >>= 1;
	solve(a, n);
}
