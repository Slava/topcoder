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
class TheAlmostLuckyNumbersDivTwo{
public:
	int find(int a, int b){
		int res = 0;
		for (int i = a; i <= b; i++) {
			int j = i, c = 0;
			for (; j; j /= 10)
				if (j % 10 != 4 && j % 10 != 7)
					c++;
			if (c < 2)
				res++;
		}
		return res;
	}
};


