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

/* START */
class ConvexSequence{
public:
	long long getMinimum(vector <int> a){
		bool ok = 1;
		for (int i = 1; i < (int)a.size() - 1; i++)
			if (a[i - 1] + a[i + 1] < 2 * a[i])
				ok = 0;
		if (ok) return 0LL;
		return res;
	}
};


