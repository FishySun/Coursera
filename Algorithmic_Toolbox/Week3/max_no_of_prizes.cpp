/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
using namespace std;

vector <long long> a;

void solve(long long n, long long k) {
		if(n <= 2*k) {
				a.emplace_back(n);
				return;
		}
		else {
				a.emplace_back(k);
				solve(n-k, k+1);
		}
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		long long n;
		cin >> n;
		solve(n, 1);
		cout << a.size() << '\n';
		for(auto &i : a) {
				cout << i << " ";
		}
		cout << '\n';
}
