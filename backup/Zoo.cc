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
class Zoo{
public:
	long long theCount(vector<int> a){
		sort(a.begin(), a.end());
		long long res = 1;
		vector<int>c(50, 0);
		for (int i = 0; i < a.size(); i++)
			c[a[i]]++;
		bool sig = 0, end = 0;
		for (int i = 0; i < 50; i++)
			if ((c[i] == 2 && sig) || c[i] > 2 || (c[i] && end))
				return 0;
			else if (c[i] == 2)
				res <<= 1;
			else if(c[i] == 1)
				sig = 1;
			else if (!c[i])
				end = 1;
		if (sig)
			res <<= 1;
		return res;
	}
};


