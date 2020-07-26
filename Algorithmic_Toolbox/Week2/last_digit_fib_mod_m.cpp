/* Author: Prasun Biswas */

#include <iostream>
using namespace std;

long long getPissanoPeriod(long long m) {
        long long a=0, b=1, c=0;
        for(long long i=0; i<m*m; ++i) {
                c = (a+b)%m;
                a = b;
                b = c;
                if (a == 0 && b == 1) {
                    return (i+1);       // Probably the compiler throws
                                        // a warning here.
                }
        }
}

int solve(long long n, long long m) {
        long long reduced_n = n%getPissanoPeriod(m);
        long long a=0, b=1, c=reduced_n;
        for (int i=2; i<=reduced_n; ++i) {
                c = (a+b)%m;
                a = b;
                b = c;
        }
        return c%m;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long n, m;
        cin >> n >> m;
        cout << solve(n, m) << '\n';
}
