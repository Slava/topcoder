// imslavko
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)
#define abs(x) (x<0?-(x):x)

/* START */
class ContiguousCacheEasy{
public:
	int bytesRead(int n, int k, vector<int> addresses){
		int res = 0;
#define r (l+k-1)
		int l = 0;
		for (vector<int>::iterator i = addresses.begin(); i != addresses.end(); i++) {
			if (*i >= l && *i <= r)
				continue;
			int p1 = *i - k + 1,
				p2 = *i, 
				d1 = abs(p1 - l), d2 = abs(p2 - l);
			if (d1 < d2) {
				l = p1; res += min(d1, k);
			}
			else {
				l = p2; res += min(d2, k);
			}
		}
		return res;
	}
};


