/* Author: Prasun Biswas */

#include <iostream>
using namespace std;

int solve(int m) {
        int count = 0;
        int a[] = {10, 5, 1};
        for (int i=0; i<3; ++i) {
                count += m/a[i];
                m = m%a[i];
        }
        return count;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int m;
        cin >> m;
        cout << solve(m) << '\n';
}
