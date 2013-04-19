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
typedef long long longlong;


class TheHexagonsDivOne{
public:
	longlong res, c[160][7];
	longlong count(int n) {
		for (int i = 1; i < 160; i++)
			for (int j = 1; j <= min(i, 6); j++) {
				if (j == 1 || j == i - 1)
					c[i][j] = i;
				else if (i == j)
					c[i][j] = 1;
				else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		res = 0;
		if (n > 3) res += 32LL * c[n - 1][3];
		if (n > 4) res += 1152LL * c[n - 1][4];
		if (n > 5) res += 5760LL * c[n - 1][5];
		if (n > 6) res += 7680LL * c[n - 1][6];
		res *= n << 1;
		return res;
	}
};

