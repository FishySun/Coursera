/* Author: Prasun Biswas */

#include <bits/stdc++.h>
using namespace std;

 int binsearch(const vector <int> &a, int key) {
	 int p = 0;
	 int n = a.size();
	 for (int i=n/2; i>=1; i/=2) {
		 while (i+p < n && a[i+p] <= key) p += i;
	 }
	 if (a[p] == key) return p;
	 else return -1;
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int &i : a) cin >> i;
	int k;
	cin >> k;
	int temp;
	while (k--) {
		cin >> temp;
		cout << binsearch(a, temp) << ' ';
	}
	cout << '\n';
}
