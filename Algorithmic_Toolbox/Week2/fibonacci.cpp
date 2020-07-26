/* Author: Prasun Biswas */

#include <iostream>
#include <vector>

using namespace std;

long long solve(long long n) {
        vector <long long> a;
        a.push_back(0);
        a.push_back(1);
        for (long long i=2; i<=n; ++i) {
                a.push_back(a[i-1] + a[i-2]);
        }
        return a[n];
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
}
