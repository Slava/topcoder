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
class MagicDiamonds{
public:
	long long minimalTransfer(long long n){
		long long i = 2;
		bool prime = 1;
		if (n == 1)
			return 1;
		if (n == 3)
			return 3;
		for (; i * i <= n; i++)
			if (n % i == 0)
				prime = 0;
		if (prime)
			return 2;
		return 1;
	}
};


