// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define all(c) c.begin(),c.end() 

typedef vector<int> vi;
typedef pair<int,vi> pivi;


pivi solve(vi h) {
	int n = (int)h.size();
	vector<pair<int,int> > a(n);
	for (int i = 0; i < n; i++)
		a[i] = mp(h[i], i);
	sort(a.begin(), a.end());
	vi b;
	for (int i = 0; i < n; i++) {
		pivi res = mp(1<<30,vi(n));
		int x = a[i].first, k = a[i].second;
	
		for (int j = 0; j < (int)b.size(); j++) {
			vi c = b;
			c.insert(c.begin()+j, k);
			int cnt = 0;
			for (int l = 1; l < (int)c.size(); l++)
				cnt += max(h[c[l]],h[c[l-1]]);
			res = min(res, mp(cnt,c));
			reverse(c.begin(), c.end());
			res = min(res, mp(cnt,c));
		}

		b.pb(k);
		int cnt = 0;
		for (int l = 1; l < (int)b.size(); l++)
			cnt += max(h[b[l]],h[b[l-1]]);
		res = min(res, mp(cnt,b));
		reverse(b.begin(), b.end());
		res = min(res, mp(cnt,b));

		b = res.second;
	}

	int cnt = 0;
	for (int i = 1; i < (int)b.size(); i++)
		cnt += max(h[b[i]],h[b[i-1]]);
	return mp(cnt,b);
}

class TheBrickTowerMediumDivOne {
	public:
	vector <int> find(vector <int> heights) {
		return solve(heights).second;
	}
};
 