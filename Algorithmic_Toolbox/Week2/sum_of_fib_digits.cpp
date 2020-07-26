/* Author: Prasun Biswas */

#include <iostream>
using namespace std;


int solve(long long n) {
        int reduced_n = n%60 + 2;
        long long a=0, b=1, c=a+b;
        for(int i=2; i<=reduced_n; ++i) {
                c = (a+b)%10;
                a = b;
                b = c;
        }
        if(c) {
                return c-1;
        }
        else {
                return 9;
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
}
