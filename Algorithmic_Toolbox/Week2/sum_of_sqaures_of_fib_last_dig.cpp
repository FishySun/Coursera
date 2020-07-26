/* Author: Prasun Biswas */

#include <iostream>
using namespace std;

int solve(long long n) {
        long long reduced_n = n%60;
        long long a=0, b=1, c=reduced_n;
        for (int i=2; i<=reduced_n; ++i) {
                c = (a+b)%10;
                a = b;
                b = c;
        }
        return c%10;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long n;
        cin >> n;
        cout << (solve(n) * solve(n+1))%10 << '\n';
}
