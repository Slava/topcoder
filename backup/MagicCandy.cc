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

int a[200], u[200];
class MagicCandy{
public:
	int whichOne(int n){
		if (n < 3) return n;
		int k = 3, pl = 2, cnt = 0, cur = 2;
		while(k <= n) {
			cur = k;
			k += pl;
			cnt++;
			if (cnt == 2) {
				cnt = 0;
				pl++;
			}
		}
		return cur;
	}
};

