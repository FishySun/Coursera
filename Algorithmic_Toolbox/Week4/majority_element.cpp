/* Author: Prasun Biswas */
/* This is the actual divide & conquer approach and works in O(nlogn) time complexity */

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <long long> a(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end()), n/=2;
	long long temp = a[0]; 
	int count = 1;
	for (auto it = a.begin()+1; it!=a.end(); ++it) {
		if (*it == temp) {
			++count;
			if (count > n) {
				cout << "1\n";
				exit(0);
			}
		}
		else 
			count = 1;
		temp = *it;
	}
	cout << "0\n";
}
