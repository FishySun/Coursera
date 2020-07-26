/* Author: Prasun Biswas */

#include <bits/stdc++.h>
using namespace std;

long merge(vector <long> &a, int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;
	vector <long> b(n1+1), c(n2+1);
	for (int i=0; i<n1; ++i)
		b[i] = a[l+i];
	for (int i=0; i<n2; ++i)
		c[i] = a[mid+i+1];
	b[n1] = __LONG_MAX__;
	c[n2] = __LONG_MAX__;
	int count = 0;
	int i=0, j=0;
	for (int k=l; k<=r; ++k) {
		if (b[i] <= c[j]) {
			a[k] = b[i++];
		}
		else {
			a[k] = c[j++];
			count += (n1 - i);
		}
	}
	return count;
}

long merge_sort(vector <long> &a, int l, int r) {
	if (l < r) {
		int mid = (l+r)/2;
		long x = merge_sort(a, l, mid);
		long y = merge_sort(a, mid+1, r);
		long z = merge(a, l, mid, r);
		return (x + y + z);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <long> a(n);
	for (long &i : a) cin >> i;
	cout << merge_sort(a, 0, n-1) << '\n';
}
