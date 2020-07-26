/* Author: Prasun Biswas */

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first != b.first) 
		return a.first < b.first;
	else 
		return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s, p;
	cin >> s >> p;
	int a, b;
	vector <pair<int, int>> segments;
	for (int i=0; i<s; ++i) {
		cin >> a >> b;
		segments.emplace_back(a, 1);
		segments.emplace_back(b, 3);
	}
	vector <int> points(p);
	for (int &i : points) {
		cin >> i;
		segments.emplace_back(i, 2);
	}
	sort(segments.begin(), segments.end(), comp);
	int ans = 0;
	unordered_map <int, int> m;
	for (auto &i : segments) {
		if (i.second == 2) {
			m[i.first] = ans;
		}
		else if (i.second == 1)
			++ans;
		else 
			--ans;
	}
	for (auto &i : points) cout << m[i] << ' ';
	cout << '\n';
}
