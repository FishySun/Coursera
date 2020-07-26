/* Author: Prasun Biswas */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct item {
        int value;
        int weight;
        item(int v, int w): value(v), weight(w) {}
};

bool comp(struct item a, struct item b) {
        double frac1 = (static_cast<double>(a.value))/(a.weight);
        double frac2 = (static_cast<double>(b.value))/(b.weight);
        return (frac1 > frac2);
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n, W;
        cin >> n >> W;
        vector <struct item> v;
        int value, weight;
        for (int i=0; i<n; ++i) {
            cin >> value >> weight;
            v.emplace_back(value, weight);
        }

        sort(v.begin(), v.end(), comp);
        
        double profit = 0.0;
        for(auto &i : v) {
                int a = min(i.weight, W);
                profit += (a/static_cast<double>(i.weight))*(i.value);
                W -= a;
                if(!W){
                        break;
                }
        }
        cout << setprecision(20) << profit << '\n';
}
