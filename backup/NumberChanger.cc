// imslavko
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

/* START */
vector<int> u, a;
int mc;

void dfs(int v) {
	u[v]  = 1;
	mc++;
	if (!u[a[v]])dfs(a[v]);
}

class NumberChanger{
public:
	int transform(string start, string finish) {
		a.clear(); int ans = (1 << 30);
		for (int i = 0; i < (int)start.size(); i++)
			a.pb(i);
		do {
			u.assign(a.size(), 0);
			int count = 0;
			for (int i = 0; i < (int)a.size(); i++)
				if (!u[i]) {
					mc = -1;
					dfs(i);
					count += mc;
				}
			for (int i = 0; i < (int)a.size(); i++)
				count += max(start[a[i]], finish[i]) - min(start[a[i]], finish[i]);
			ans = min(ans, count);
		} while(next_permutation(a.begin(), a.end()));
		return ans;
	}
};


