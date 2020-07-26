/* Author: Prasun Biswas */

#include <iostream>
using namespace std;

long long solve(long long a, long long b) {
        if(!b) {
                return a;
        }
        else {
                return solve(b, a%b);
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long a, b;
        cin >> a >> b;
        long long res = (a>b)? solve(a, b):solve(b, a);
        cout << (a*b)/res << "\n";
}
