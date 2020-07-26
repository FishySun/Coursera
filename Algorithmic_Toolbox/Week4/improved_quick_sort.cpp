/* Author: Prasun Biswas */

#include <bits/stdc++.h>
using namespace std;

void partition(vector <long long> &a, int l, int r, int &lower_bound, int &higher_bound) {
	srand(time(0));
	int pIndex = l + rand() % (r + 1 - l);
	swap(a[l], a[pIndex]);
	long long pivot = a[l];
	int x = l;
	for (int i=l+1; i<=r; ++i) {
		if (a[i] <= pivot) {
			++x;
			swap(a[x], a[i]);
		}
	}
	swap(a[l], a[x]);
	higher_bound = x + 1;
	int y = l;
	for (int i=l+1; i<r; ++i) {
		if (a[i] < pivot) {
			++y;
			swap(a[y], a[i]);
		}
	}
	lower_bound = y;
}

void quick_sort(vector <long long> &a, int l, int r) {
	if (l < r) {
		int i=0, j=0;
		partition(a, l, r, i, j);
		quick_sort(a, l, i);
		quick_sort(a, j, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <long long> a(n);
	for (long long &i : a) cin >> i;
	quick_sort(a, 0, n-1);
	for (long long &i : a) cout << i << ' ';
	cout << '\n';
}
