/* Author : Prasun Biswas */
/* This code uses the hashbased concept and works in O(n) time */

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map <long long, int> m;
	for (int i=0, temp; i<n; ++i) {
		cin >> temp, ++m[temp];
	}
	n >>= 1;
	for (auto &i : m) {
		if (i.second > n) {
			cout << "1\n";
			exit(0);
		}
	}
	cout << "0\n";
}
