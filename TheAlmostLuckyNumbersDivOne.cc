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
class TheAlmostLuckyNumbersDivOne{
public:
	long long res, L, R;
	void dfs(long long n, bool w) {
		if (n >= L && n <= R) res++;
		if (n > R)return ;
		if (w)
			dfs(n * 10 + 4, 1),
			dfs(n * 10 + 7, 1);
		else for (int i = 0; i < 10; i++)
			if (i != 4 && i != 7)
				dfs(n * 10 + i, 1);
			else dfs(n * 10 + i, 0);
	}
	long long find(long long a, long long b){
		res = 0;
		L = a; R = b;
		for (int i = 1; i < 10; i++)
			if (i != 4 && i != 7)
				dfs(i, 1);
			else dfs(i, 0);
		return res;
	}
};


