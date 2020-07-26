/* Author: Prasun Biswas */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Interval {
		int a;
		int b;
		int state;
		Interval(int A, int B):a(A), b(B), state(1) {}
};

int getMinRight(vector <Interval> &a) {			
		long long m = LONG_MAX;
		for(auto it=a.begin(); it!=a.end(); ++it) {
				if((it->state) && (it->b < m)) {
					m = it->b;
				}
		}
		return m;
}

void solve(vector <Interval> &a) {
		vector <long long> Sol;
		int count = 0;
		while(count < static_cast<int>(a.size())){
				int m = getMinRight(a); 
				for(auto &I : a) {
							if((I.state) && (I.a <= m) && (I.b >= m)) {
									I.state = 0;
									++count;
							}
				}
				Sol.push_back(m);
		}
		cout << Sol.size() << '\n';
		for(auto &i : Sol) {
				cout << i << ' ';
		}
		cout << '\n';
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		long long n, a, b;
		cin >> n;	
		vector <Interval> v;
		while(n--) {
				cin >> a >> b;		
				v.emplace_back(a, b);	
		}
		solve(v);
}
