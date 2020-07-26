/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int> &a, int l, int n) {
		int numRefills=0, currRefill=0;
		while(currRefill < n) {	
				int lastRefill = currRefill;
				while((currRefill < n) && (a[currRefill+1] - a[lastRefill] <= l)) {
						++currRefill;
				}
				if(currRefill == lastRefill) {
						return -1;
				}
				if(currRefill < n) {
						++numRefills;
				}

		}
		return numRefills;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		int target, n, capacity;
		cin >> target >> capacity >> n;
		vector <int> a;
		a.emplace_back(0);
		for(int i=0; i<n; ++i) {
				int t;
				cin >> t;
				a.emplace_back(t);
		}
		a.emplace_back(target);
		cout << solve(a, capacity, ++n) << '\n';
}
