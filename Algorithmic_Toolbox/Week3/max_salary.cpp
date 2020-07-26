/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
		a += b;
		b += a;
		return (a >= b);
}

void solve(vector <string> &a) {
		sort(a.begin(), a.end(), comp);
		for(auto &i : a) {
				cout << i;
		}
		cout << '\n';
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		size_t n;
		cin >> n;
		vector <string> a(n);
		for(size_t i=0; i<n; ++i) {
				cin >> a[i];
		}
		solve(a);
}
