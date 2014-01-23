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

char s[20];
int rev(int x) {
	int l = sprintf(s, "%d", x);
	reverse(s, s + l);
	sscanf(s, "%d", &x);
	return x;
}

class ReversedSum{
public:
	int getReversedSum(int x, int y){
		return rev(rev(x) + rev(y));
	}
};


