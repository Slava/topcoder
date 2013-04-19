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

class BitwiseEquations{
public:
	long long kthPlusOrSolution(int x, int k){
		long long res = 0;
		int j = 0;
		for (int i = 0; i < 32; i++) {
			while (j < 32 && (x & (1 << j)))
				j++;
			if (k & (1 << i))
				res |= (1LL << j);
			j++;
		}
		return res;
	}
};


