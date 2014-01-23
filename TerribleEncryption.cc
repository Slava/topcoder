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

int gcd(int a, int b, int &x, int &y) {
	if (!a) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1, d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

class TerribleEncryption{
public:
	string decrypt(string pool, vector <int> a, vector <int> m){
		int n = (int)a.size(), x, y;
		string res;
		for (int i = 0; i < n; i++) {
			gcd(a[i], m[i], x, y);
			x = (x % m[i] + m[i]) % m[i];
			x %= (int)pool.size();
			res.pb(pool[x]);
		}
		return res;
	}
};


