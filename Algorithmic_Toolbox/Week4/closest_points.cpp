/* Author: Prasun Biswas */
/* This was the hardest problem of this week and I spent total 2 days understanding 
 * and implementing the algorithm. For anyone stuck, here's a tip : Follow the section 
 * in the CLRS book which gives the algorithm and also has a 
 * little pseudo code which helped me a lot!
 * Don't give up! */

/* This pragma optimizatins are optional, the code will pass without these as well */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::min;
using std::ios_base;
using std::setprecision;

double calcDist(const vector <pair <long long, long long>> &P) {
	double d = DBL_MAX;
	for (size_t i=0; i<P.size(); ++i) {
		for (size_t j=i+1; j<P.size(); ++j) {
			double k1 = abs(P[i].first - P[j].first);
			double k2 = abs(P[i].second - P[j].second);
			double k3 = k1*k1 + k2*k2;
			double k4 = sqrt(k3);
			d = min(d, k4);
		}
	}
	return d;
}

double closestPair(const vector <pair <long long, long long>> &Px, const vector <pair <long long, long long>> &Py) {
	if (Px.size() <= 3) {
		return calcDist(Px);
	}
	else {
		vector <pair<long long, long long>> Qx, Qy, Rx, Ry;
		for (size_t i=0; i<Px.size()/2; ++i) Qx.emplace_back(Px[i]);
		for (size_t i=Px.size()/2; i<Px.size(); ++i) Rx.emplace_back(Px[i]);
		int xq = Qx[Qx.size()-1].first;
		for (size_t i=0; i<Py.size(); ++i) {
			if (Py[i].first <= xq) Qy.emplace_back(Py[i]);
			else Ry.emplace_back(Py[i]);
		}
		double d = min(closestPair(Qx, Qy), closestPair(Rx, Ry));
		int xy = Qx[Qx.size()-1].first;
		vector <pair <long long, long long>> Sy;
		size_t i=0, j=0;
		while (i<Qy.size() && j<Ry.size()) {
			if (Qy[i].second <= Ry[i].second) {
				if (abs(Qy[i].first - xy) <= d) 
					Sy.emplace_back(Qy[i++]);
				else
					++i;
			}
			else {
				if (abs(Ry[j].first - xy) <= d)
					Sy.emplace_back(Ry[j++]);
				else 
					++j;
			}
			
		}
		while (i<Qy.size()) {
			if (abs(Qy[i].first - xy) <= d) 
					Sy.emplace_back(Qy[i++]);
				else
					++i;
		}
		while (j<Ry.size()) {
			if (abs(Ry[j].first - xy) <= d)
					Sy.emplace_back(Ry[j++]);
				else 
					++j;
		}
		for (size_t k=0; k<Sy.size(); ++k) {
			int count = 0;
			for (size_t p=k+1; p<Sy.size() && count < 7; ++p) {
				double k1 = abs(Sy[k].first - Sy[p].first);
				double k2 = abs(Sy[k].second - Sy[p].second);
				double k3 = k1*k1 + k2*k2;
				double k4 = sqrt(k3);
				d = min(d, k4);
				++count;
			}
		}
		return d;
	}
}

inline bool comp1(const pair<long long, long long> &a, const pair <long long, long long> &b) {
	return (a.first < b.first);
}

inline bool comp2(const pair<long long, long long> &a, const pair <long long, long long> &b) {
	return (a.second < b.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	size_t n;
	cin >> n;
	long long x, y;
	vector <pair <long long, long long>> Points;
	for (size_t i=0; i<n; ++i) {
		cin >> x >> y;
		Points.emplace_back(x, y);
	}
	sort(Points.begin(), Points.end(), comp1);
	vector <pair <long long, long long>> Px = Points;
	sort(Points.begin(), Points.end(), comp2); 
	vector <pair <long long, long long>> Py = Points;
	cout << setprecision(30) << closestPair(Px, Py) << '\n';
}
