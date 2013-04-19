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

const int Mod = 1000000007;
typedef long long Int;
/* START */

inline Int mod(Int x) {
	if (x >= Mod)
		x %= Mod;
	return x;
}

int k;
Int fullbrick[60];
bool u[60][60];
Int dp[60][60];

Int count(int h, int w) {
	if (w <= 0)
		return 1;
	if (!h)
		return 1;
	if (u[h][w])
		return dp[h][w];
	Int &res = dp[h][w];
	res = 0;
	u[h][w] = 1;
	for (int i = 0; i < w; i++) {
		res = mod(res + mod(fullbrick[i] * mod(count(h-1,i) * count(h, w - i - 1))));
//		cout << "to " << h << " " << w << " plused and " << res << endl;
	}
	res = mod(res + mod(fullbrick[w] * count(h-1,w)));
//	cout << h << " " << w << "  => " << res << endl;
	return res;
}

class BricksN{
public:
	int countStructures(int w, int h, int k) {
		::k = k;
		fullbrick[0] = 1;
		for (int i = 1; i <= w; i++) {
			fullbrick[i] = 0;
			for (int j = 1; j <= k && i - j >= 0; j++)
				fullbrick[i] = mod(fullbrick[i] + fullbrick[i - j]);
//			cout << "fullbrick[" << i << "] = " << fullbrick[i] << endl;
		}
		memset(u, 0, sizeof u);
		Int res = count(h,w);
		return (int)res%Mod;
	}
};


