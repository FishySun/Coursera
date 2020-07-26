/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
		return (a > b);
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for(int &i : a)
			cin >> i;
		for(int &i : b)
			cin >> i;
		sort(a.begin(), a.end(), comp);
		sort(b.begin(), b.end(), comp);
		long long profit = 0;
		for(int i=0; i<n; ++i) {
				profit += (static_cast<long long>(a[i]) * b[i]);
		}
		cout << profit << '\n';
}
