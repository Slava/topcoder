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
const int N = 100010;
bool d[N];

class CompositeSmash{
public:
	string thePossible(int N, int target){
		if (N % target != 0)
			return "No";
		memset(d, 0, sizeof d);
		d[target] = 1;
		for (int i = target + 1; i <= N; i++) {
			bool can = 1, was = 0;
			for (int j = 2; j * j <= i; j++)
				if (i % j == 0) {
					was = 1;
					can &= d[i / j] | d[j];
				}
			d[i] = was & can;
		}
		return d[N] ? "Yes" : "No";
	}
};


