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
class MarbleDecoration{
public:
	int maxLength(int R, int G, int B){
		int a[3] = {R, G, B};
		sort(a, a + 3);
		reverse(a, a + 3);
		int res = min(a[0], a[1]) * 2;
		if (a[0] != a[1])
			res++;
		return res;
	}
};


